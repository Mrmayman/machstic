#ifndef MACHSTIC_HPP
#define MACHSTIC_HPP

#include <variant>

template <typename... __machstic_Ts>
struct __machstic_Overloaded : __machstic_Ts... {
    using __machstic_Ts::operator()...;
};

template <typename... Ts>
__machstic_Overloaded(Ts...) -> __machstic_Overloaded<Ts...>;

template <typename __machstic_Variant, typename... __machstic_Visitors>
void match(__machstic_Variant&& __machstic_var, __machstic_Visitors&&... __machstic_visitors) {
    return std::visit(
        __machstic_Overloaded {
            std::forward<__machstic_Visitors>(__machstic_visitors)...
        },
        std::forward<__machstic_Variant>(__machstic_var)
    );
}

template <typename __machstic_Variant, typename... __machstic_Visitors>
void match_mut(__machstic_Variant& __machstic_var, __machstic_Visitors&&... __machstic_visitors) {
    return std::visit(
        __machstic_Overloaded {
            std::forward<__machstic_Visitors>(__machstic_visitors)...
        },
        __machstic_var
    );
}

#endif
