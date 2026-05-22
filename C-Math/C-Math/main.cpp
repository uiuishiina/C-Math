#include"../Four arithmetic operations/Four arithmetic operations.h"
#include<vector>

int main() {

	auto ans = normal_sum(100, 200, 300,600);

	std::vector<int> vec_{ 10,20,30,40,50,60,70,80,90 };

	auto ranges = ranges_sum(vec_);

	return 0;
}