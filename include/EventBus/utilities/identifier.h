#pragma once

namespace dexode {

    namespace eventbus {

        namespace utilities {

            template <typename T>
            size_t identifier() {
                return typeid(T).hash_code();
            };

        };

    };

};