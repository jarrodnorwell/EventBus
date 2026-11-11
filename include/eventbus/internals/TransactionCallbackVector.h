#pragma once

#include "eventbus/internals/CallbackVector.h"

#include <algorithm>
#include <functional>
#include <vector>

namespace eventbus {

	namespace internals {

		template <typename Event>
		struct TransactionCallbackVector : public CallbackVector {
			using CallbackType = std::function<void(const Event)>;
			using ContainerElement = std::pair<int, CallbackType>;
			using ContainerType = std::vector<ContainerElement>;

			void remove(const int token) override {
				if (transaction_index > 0)
					return to_remove.push_back(token);

				container.erase(std::remove_if(container.begin(), container.end(), [token](auto& element) {
					return element.first == token;
				}), container.end());
			};

			void add(const int token, CallbackType type) {
				if (transaction_index > 0)
					to_add.emplace_back(token, type);
				else
					container.emplace_back(token, type);
			};

			void begin() {
				++transaction_index;
			};

			void commit() {
				--transaction_index;
				if (transaction_index > 0)
					return;
				transaction_index = 0;

				if (!to_add.empty()) {
					container.insert(container.end(), to_add.begin(), to_add.end());
					to_add.clear();
				}

				if (!to_remove.empty()) {
					std::for_each(to_remove.begin(), to_remove.end(), [this](auto& element) {
						this->remove(token);
					});
					to_remove.clear();
				}
			};
			
			ContainerType container, to_add;
			int transaction_index{0};
			std::vector<int> to_remove;
		};

	};

};