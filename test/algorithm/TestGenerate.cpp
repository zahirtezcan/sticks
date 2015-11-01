#include <stx/algorithm/Generate.h>
#include <vector>
#include <iostream>

template<typename Container>
bool ElementsEqual(const Container& c1, const Container& c2) {
	if (c1.size() != c2.size()) return false;

	for (typename Container::size_type i = 0; i < c1.size(); ++i) {
		if (c1[i] != c2[i]) return false;
	}

	return true;
}

int TestGenerateBasic()
{
	std::cout << "Testing Generate...";

	std::vector<int> base, generated;
	base.assign(100, 13);
	generated.resize(base.size());
	stx::Generate(generated.begin(), generated.end(), [&]() { return base[0]; });

	if (!ElementsEqual(base, generated)) {
		std::cerr << "Generate basic failed!" << std::endl;
		return -1;
	}

	std::cout << "OK\n";
	return 0;
}

int TestGenerateIndexed()
{
	std::cout << "Testing GenerateIndexed...";

	std::vector<int> base, generated;
	base.resize(100);
	stx::GenerateIncrement(base.begin(), base.end(), 13);

	generated.resize(base.size());
	stx::GenerateIndexed(generated.begin(), generated.end(), [&](int i) { return base[i]; });

	if (!ElementsEqual(base, generated)) {
		std::cerr << "GenerateIndex failed!" << std::endl;
		return -1;
	}

	std::cout << "OK\n";
	return 0;
}

int main()
{
	if (TestGenerateBasic() != 0) return -1;
	if (TestGenerateIndexed() != 0) return -1;

	return 0;
}
