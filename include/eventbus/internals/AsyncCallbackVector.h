#pragma once

#include "eventbus/internals/CallbackVector.h"

#include <algorithm>
#include <functional>
#include <vector>

namespace eventbus {

	namespace internals {

		template <typename Event>
		struct AsyncCallbackVector : public CallbackVector {
			using CallbackType = std::function<void(const Event)>;
			using ContainerElement = std::pair<int, CallbackType>;

			void remove(const int token) override {
				container.erase(std::remove_if(container.begin(), container.end(), [token](auto& element) {
					return element.first == token;
				}), container.end());
			};
			
			void add(const int token, CallbackType type) {
				container.emplace_back(token, std::move(type));
			};
			
			std::vector<ContainerElement> container;
		};

	};

};