#include <stx/algorithm/PartialSum.h>
#include <gtest/gtest.h>
#include <vector>
#include <iterator>

TEST(PartialSum, Empty)
{
	std::vector<int> v;
	std::vector<int> u;

	stx::PartialSum(v.begin(), v.end(), std::back_inserter(u));

	EXPECT_TRUE(u.empty());
}


TEST(PartialSum, One)
{
	std::vector<int> v = { 1 };
	std::vector<int> u;

	stx::PartialSum(v.begin(), v.end(), std::back_inserter(u));

	EXPECT_EQ(std::vector<int>::size_type(1), u.size());
	EXPECT_EQ(1, u[0]);
}

TEST(PartialSum, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> u;

	stx::PartialSum(v.begin(), v.end(), std::back_inserter(u));

	EXPECT_EQ(std::vector<int>::size_type(3), u.size());
	EXPECT_EQ(1, u[0]);
	EXPECT_EQ(3, u[1]);
	EXPECT_EQ(6, u[2]);

}

