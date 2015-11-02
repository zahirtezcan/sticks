#include <stx/algorithm/Rotate.h>
#include <iostream>

template<typename Range>
bool RangeEquals(Range& r1, Range&& r2)
{
	using std::begin;
	using std::end;

	auto b1 = begin(r1);
	auto e1 = end(r1);
	auto b2 = begin(r2);
	auto e2 = end(r2);

	while (b1 != e1 && b2 != e2) {
		if (*b1 != *b2) {
			return false;
		}
		++b1;
		++b2;
	}

	return b1 == e1 && b2 == e2;
}

int main()
{
	int a[] = { 1, 2, 3 };

	stx::Rotate(std::begin(a), std::begin(a), std::end(a));
	if (!RangeEquals(a, { 1, 2, 3 })) {
		std::cerr << "Empty rotate failed!" << std::endl;
		return -1;
	}
	
	stx::Rotate(std::begin(a), std::end(a), std::end(a));
	if (!RangeEquals(a, { 1, 2, 3 })) {
		std::cerr << "Reverse empty rotate failed!" << std::endl;
		return -1;
	}
	
	stx::Rotate(std::begin(a), std::begin(a) + 1, std::end(a));
	if (!RangeEquals(a, { 2, 3, 1 })) {
		std::cerr << "Basic rotate failed!" << std::endl;
		return -1;
	}

	std::cout << "OK" << std::endl;
}
