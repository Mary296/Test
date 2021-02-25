#include <iostream>
#include <algorithm>
#include <random>
#include <unordered_set>
#include <vector>

std::vector<std::vector<int>> generate(size_t const n, size_t const max_size) {
	std::vector<std::vector<int>> result;
	
	std::random_device random_device;
	std::default_random_engine random_engine(random_device());
	std::uniform_int_distribution<size_t> size_generator(0, max_size);
	std::uniform_int_distribution<int> value_generator;

	std::unordered_set<size_t> sizes;

	while (sizes.size() != n)
		sizes.insert(size_generator(random_device));

	for (size_t size : sizes)
		result.emplace_back(size);

	for (std::vector<int> &vector : result)
		std::generate(vector.begin(), vector.end(),
			[&value_generator, &random_engine]() {
		return value_generator(random_engine);
	});

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

std::vector<std::vector<int>> generate(size_t const n) {
	return generate(n, 256);
}

int main() {

	int n;
	std::cin >> n;
	auto result = generate(n);

	for (size_t i = 0; i < result.size(); i++) {
		for (size_t j = 0; j < result[i].size(); j++) {
			std::cout << result[i][j] << ' ';
		}
		std::cout << '\n';
	}
}
