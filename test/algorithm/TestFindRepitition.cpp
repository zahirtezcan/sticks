#include <stx/algorithm/FindRepitition.h>
#include <gtest/gtest.h>
#include <vector>

TEST(FindRepitition, Empty)
{	
	std::vector<int> v;
	auto result = stx::FindRepitition(v.begin(), v.end(), 1, -1);

	EXPECT_EQ(v.end(), result);
}

TEST(FindRepitition, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	auto result = stx::FindRepitition(v.begin(), v.end(), 1, 2);

	EXPECT_EQ(v.begin() + 1, result);
}

TEST(FindRepitition, Repeated)
{
	std::vector<int> v = { 1, 2, 2, 3, 2, 2, 2 };
	auto result = stx::FindRepitition(v.begin(), v.end(), 3, 2);

	EXPECT_EQ(v.end() - 3, result);
}

TEST(FindRepitition, NoRepitition)
{
	std::vector<int> v = { 1, 2, 2, 3, 2, 2 };
	auto result = stx::FindRepitition(v.begin(), v.end(), 3, 2);

	EXPECT_EQ(v.end(), result);
}

