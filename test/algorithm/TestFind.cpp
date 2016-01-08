#include <stx/algorithm/Find.h>
#include <gtest/gtest.h>
#include <vector>

TEST(Find, Empty)
{
	std::vector<int> v;

	auto result = stx::Find(v.begin(), v.end(), [](int x) { return x == 3; });

	EXPECT_EQ(v.end(), result);
}

TEST(Find, Basic)
{
	std::vector<int> v = { 1, 2 ,3 };

	auto result = stx::Find(v.begin(), v.end(), [](int x) { return x == 2; });

	EXPECT_EQ(v.begin() + 1, result);
}

TEST(FindValue, Empty)
{
	std::vector<int> v;

	auto result = stx::FindValue(v.begin(), v.end(), 0);

	EXPECT_EQ(v.end(), result);
}

TEST(FindValue, Basic)
{
	std::vector<int> v = { 1, 2 ,3 };

	auto result = stx::FindValue(v.begin(), v.end(), 2);

	EXPECT_EQ(v.begin() + 1, result);
}


