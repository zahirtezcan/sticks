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

int main()
{
	std::vector<int> base, generated;
	base.assign(100, 13);
	generated.resize(base.size());
	stx::Generate(generated.begin(), generated.end(), [&]() { return base[0]; });

	if (!ElementsEqual(base, generated)) {
		std::cerr << "Generate failed!" << std::endl;
		return -1;
	}

	return 0;
}
