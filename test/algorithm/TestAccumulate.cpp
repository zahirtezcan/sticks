#include <stx/algorithm/Accumulate.h>
#include <gtest/gtest.h>
#include <vector>

TEST(Accumulate, Empty)
{
	std::vector<int> v;
	int initial = 0;
	int result = stx::Accumulate(v.begin(), v.end(), initial);

	EXPECT_EQ(initial, result);
}

TEST(Accumulate, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	int initial = 0;
	int result = stx::Accumulate(v.begin(), v.end(), initial);

	EXPECT_EQ(6, result);
}


