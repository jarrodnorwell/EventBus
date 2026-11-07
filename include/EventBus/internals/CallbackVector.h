#pragma once

#include <functional>
#include <utility>
#include <vector>

struct Event;

namespace eventbus {

	namespace internals {

		struct CallbackVector {
			virtual ~CallbackVector() = default;
			virtual void remove(const int) = 0;

			using CallbackType = std::function<void(const Event)>;
			using ContainerElement = std::pair<int, CallbackType>;
			using ContainerType = std::vector<ContainerElement>;

			std::vector<ContainerElement> container;
		};

	};

};