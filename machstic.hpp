#ifndef MACHSTIC_HPP
#define MACHSTIC_HPP

#include <variant>

template <typename... Ts>
struct Overloaded : Ts... {
    using Ts::operator()...;
};

template <typename... Ts>
Overloaded(Ts...) -> Overloaded<Ts...>;

template <typename Variant, typename... Visitors>
auto match(Variant&& var, Visitors&&... visitors) {
    return std::visit(Overloaded{std::forward<Visitors>(visitors)...}, std::forward<Variant>(var));
}

template <typename Variant, typename... Visitors>
auto match_mut(Variant& var, Visitors&&... visitors) {
    return std::visit(Overloaded{std::forward<Visitors>(visitors)...}, var);
}

#endif
