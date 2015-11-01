#include <stx/algorithm/Count.h>
#include <stx/algorithm/Generate.h>
#include <vector>
#include <iostream>

void Generate(std::vector<int>& list, int n, int v, int vcount)
{
	list.resize(n);
	stx::GenerateIncrement(list.begin(), list.end(), 0);
	if (vcount == 0) {
		list.erase(list.begin() + v);
	} else if (vcount > 1) {
		auto iter = list.begin();
		while (vcount > 1) {
			iter = list.insert(iter, v);
			if (iter != list.end()) {
				++iter;
			}
			--vcount;
		}
	}
}

int TestCountValue()
{
	std::cout << "Testing CountValue...";
	std::vector<int> list;
	for (int i = 0; i < 100; ++i) {
		for (int v = 0; v < i; ++v) {
			for (int c = 0; c < 10; ++c) {
				Generate(list, i, v, c);
				auto count = stx::CountValue(list.begin(), list.end(), v);
				if (count != c) {
					std::cerr << "Invalid count: " << count 
					          << " found for n: " << i
					          << " value: " << v
						  << " count: " << c
						  << std::endl;
					return -1;
				}
			}
		}
	}

	std::cout << "OK\n";
	return 0;
}

int TestCount()
{
	std::cout << "Testing Count...";
	std::vector<int> list;
	for (int i = 0; i < 100; ++i) {
		for (int v = 0; v < i; ++v) {
			Generate(list, i, v, 1);
			auto count = stx::Count(list.begin(), list.end(), [=](int x) { return x < i; });
			if (count != i) {
				std::cerr << "Invalid count: " << count 
					  << " found for n: " << i
					  << " value: " << v
					  << std::endl;
				return -1;
			}
		}
	}
	std::cout << "OK\n";
	return 0;

}

int main()
{
	if (TestCountValue() != 0) {
		return -1;
	}
	if (TestCount() != 0) {
		return -1;
	}
	
	return 0;
}

