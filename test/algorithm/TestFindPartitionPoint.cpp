#include <stx/algorithm/FindPartitionPoint.h>
#include <iostream>
#include <algorithm>
#include <vector>

void Generate(std::vector<int>& v, int n, int r)
{
	v.resize(n);
	std::iota(v.begin(), v.end(), 0);
	std::rotate(v.begin(), v.begin() + r, v.end());
}

int main()
{
	std::vector<int> v;
	for (int i = 0; i < 100; ++i) {
		for (int r = 0; r <= i; ++r) {
			Generate(v, i, r);
			auto found = stx::FindPartitionPoint(v.begin(), v.end(),
			[&] (int x) {
				return x >= v[0];
			});

			auto dist = std::distance(v.begin(), found);

			if ( (i == r && found != v.end()) || (i != r && dist != (i - r))) {
				std::cout << "Error on i: " << i << " r:" << r << std::endl;
			}
		}
	}
}
