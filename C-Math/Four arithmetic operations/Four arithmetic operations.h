#pragma once
#include"../OutPut.h"
#include<concepts>

//===================================================================================================
template<typename T>
concept Add_able = requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;
};
template<typename T>
concept Add_Equal_able = requires(T a, T b) {
    { a += b } -> std::convertible_to<T>;
};
//===================================================================================================
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
//===================================================================================================

//===================================================================================================
template<typename T>
concept Subtract_able = requires(T a, T b) {
    { a - b } -> std::convertible_to<T>;
};
template<typename T>
concept Subtract_Equal_able = requires(T a, T b) {
    { a -= b } -> std::convertible_to<T>;
};

template<Subtract_able T,Subtract_able... Args>
auto normal_subtract(T&& value, Args&&... args) {
    auto ans = (value - ... - args );
    OutPut(ans);
    return ans;
}
//===================================================================================================

//===================================================================================================
template<typename T>
concept Multiply_able = requires(T a, T b) {
    { a * b } -> std::convertible_to<T>;
};
template<typename T>
concept Multiply_Equal_able = requires(T a, T b) {
    { a *= b } -> std::convertible_to<T>;
};
template<Multiply_able... Args>
auto normal_multiply(Args&&... args) {
    auto ans = (... * args);
    OutPut(ans);
    return ans;
}

//===================================================================================================