#pragma once
#include"../OutPut.h"
#include<concepts>


template<typename T>
concept Add_able = requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;
};

template<Add_able T,Add_able... Args>
T normal_sum(Args... args) {
    T ans{};
    ((ans += args), ...);
    OutPut(ans);
    return ans;
}