#pragma once
#include"../OutPut.h"
#include<concepts>


template<typename T>
concept Add_able = requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;
};
template<typename T>
concept Add_Equal_able = requires(T a, T b) {
    { a += b } -> std::convertible_to<T>;
};

template<Add_able... Args>
auto normal_sum(Args&&... args) {
    auto ans = (... + args);
    OutPut(ans);
    return ans;
}

template<std::ranges::input_range R>
requires Add_Equal_able<std::ranges::range_value_t<R>>
auto ranges_sum(R&& r)
{
    using T = std::ranges::range_value_t<R>;
    T ans{};
    for (auto&& x : r) {
        ans += x;
    }
    OutPut(ans);
    return ans;
}