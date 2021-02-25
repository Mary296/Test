#include <iostream>
#include <algorithm>
#include <random>
#include <unordered_set>
#include <vector>

std::vector<std::vector<int>> generate(size_t const n) {
	std::vector<std::vector<int>> result;
	std::random_device random_device;
	std::default_random_engine random_engine(random_device());
	std::uniform_int_distribution<size_t> random_generator;
	std::unordered_set<size_t> sizes;
	
	while (sizes.size() != n)
		sizes.insert(random_generator(random_device));

	for (uint8_t size : sizes)
		result.emplace_back(size);

	for (size_t i = 0; i < result.size(); i++) {
		for (size_t j = 0; j < result[index].size(); j++) {
			result[i][j] = rand();
		}
	}

	for (size_t index = 0; index < result.size(); index++) {
		std::vector<int> &vector = result[index];
		if (index % 2 == 0)
			std::sort(vector.begin(), vector.end());
		else
			std::sort(vector.begin(), vector.end(),
				[](int left, int right) { return left > right; });
	}
	
	return result;
}
	
int main() {

	int n;
	std::cin >> n;
	auto result = generate(n);

	for (size_t i = 0; i < result.size(); i++) {
		for (size_t j = 0; j < result[index].size(); j++) {
			std::cout << result[i][j] << ' ';
		}
		std::cout <<'\n';
	}
}

