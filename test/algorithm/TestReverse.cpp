#include <stx/algorithm/Reverse.h>
#include <iostream>

bool AreEqual(int* a, int* b, int count)
{
	for (int i = 0; i < count; ++i) {
		if (a[i] != b[i]) {
			return false;
		}
	}

	return true;
}

int main() 
{
	int a[] = { 1, 2, 3, 4, 5 };
	int b[] = { 5, 4, 3, 2, 1 };

	if (AreEqual(a, b, 5)){
		std::cerr << "AreEqual method failed!" << std::endl;
		return -1;
	}

	stx::Reverse(std::begin(a), std::end(a));
	
	if (!AreEqual(a, b, 5)){
		std::cerr << "Reverse method failed!" << std::endl;
		return -1;
	}
	
	std::cout << "OK" << std::endl;
}
