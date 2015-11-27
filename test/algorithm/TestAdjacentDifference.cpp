#include <stx/algorithm/AdjacentDifference.h>
#include <gtest/gtest.h>
#include <vector>
#include <iterator>

TEST(AdjacentDifference, Empty)
{
	std::vector<int> v;
	std::vector<int> u;

	stx::AdjacentDifference(v.begin(), v.end(), std::back_inserter(u));

	EXPECT_TRUE(u.empty());
}

TEST(AdjacentDifference, One)
{
	std::vector<int> v = { 1 };
	std::vector<int> u;
	std::vector<int>::size_type expectedSize = 1;

	stx::AdjacentDifference(v.begin(), v.end(), std::back_inserter(u));

	EXPECT_EQ(expectedSize, u.size());
	EXPECT_EQ(1, u[0]);
}

TEST(AdjacentDifference, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> u;
	std::vector<int>::size_type expectedSize = 3;

	stx::AdjacentDifference(v.begin(), v.end(), std::back_inserter(u));

	EXPECT_EQ(expectedSize, u.size());
	EXPECT_EQ(1, u[0]);
	EXPECT_EQ(1, u[1]);
	EXPECT_EQ(1, u[2]);
}

