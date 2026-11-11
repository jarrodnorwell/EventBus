#pragma once

namespace eventbus {

	namespace internals {

		struct CallbackVector {
			virtual ~CallbackVector() = default;
			virtual void remove(const int) = 0;
		};

	};

};