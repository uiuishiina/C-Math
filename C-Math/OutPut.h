#pragma once
#include<iostream>

//@brief	=== 出力関数 ===
static void OutPut(const char* c) {
	std::cout << c << std::endl;
}

static void OutPut(const wchar_t* c) {
	 std::wcout << c << std::endl;
}

template<typename T>
static void OutPut(const T& value) {
	std::cout << value << std::endl;
}