#pragma once

#include <concepts>
#include <type_traits>

namespace dexode {

    namespace eventbus {

        namespace utilities {

            template <class Event> requires (std::same_as<Event, std::remove_cvref_t<Event>> && !std::is_pointer_v<Event>)
            constexpr bool validate() noexcept {
                return true;
            }

        };
        
    };

};