#pragma once

#include <functional>
#include <utility>
#include <vector>

namespace eventbus {

	namespace internals {

		struct CallbackVector {
			virtual ~CallbackVector() = default;
			virtual void remove(const int) = 0;
		};

	};

};