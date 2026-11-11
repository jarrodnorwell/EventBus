#pragma once

#include <concepts>
#include <type_traits>

namespace eventbus {

    namespace utilities {

        template <class Event> requires (!std::is_pointer_v<Event> && std::same_as<Event, std::remove_cvref_t<Event>>)
        constexpr bool validate() noexcept {
            return true;
        }

    };
        
};