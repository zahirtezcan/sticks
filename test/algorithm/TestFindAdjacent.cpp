#include <stx/algorithm/FindAdjacent.h>
#include <gtest/gtest.h>
#include <vector>

TEST(FindAdjacent, Empty)
{	
	std::vector<int> v;
	auto result = stx::FindAdjacent(v.begin(), v.end());

	EXPECT_EQ(v.end(), result);
}

TEST(FindAdjacent, None)
{
	std::vector<int> v = { 1, 2, 3 };
	auto result = stx::FindAdjacent(v.begin(), v.end());

	EXPECT_EQ(v.end(), result);
}

TEST(FindAdjacent, Basic)
{
	std::vector<int> v = { 1, 2, 2, 3 };
	auto result = stx::FindAdjacent(v.begin(), v.end());

	EXPECT_EQ(v.begin() + 1, result);
}


TEST(FindAdjacent, Inverted)
{
	std::vector<int> v = { 1, 1, 2, 2, 2, 2, 2 };
	auto result = stx::FindAdjacent(v.begin(), v.end(), stx::NotEquals());

	EXPECT_EQ(v.begin() + 1, result);
}

