#include <stx/algorithm/FillN.h>
#include <gtest/gtest.h>
#include <vector>

TEST(FillN, Empty)
{
	std::vector<int> v;
	stx::FillN(std::back_inserter(v), 0, -1);

	EXPECT_TRUE(v.empty());
}

TEST(FillN, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	auto result = stx::FillN(v.begin(), v.size(), -1);

	EXPECT_EQ(v.end(), result);
	EXPECT_EQ(-1, v[0]);
	EXPECT_EQ(-1, v[1]);
	EXPECT_EQ(-1, v[2]);
}

TEST(FillN, BasicOutputIterator)
{
	std::vector<int> v;
	stx::FillN(std::back_inserter(v), 3, -1);

	EXPECT_EQ(std::vector<int>::size_type(3), v.size());
	EXPECT_EQ(-1, v[0]);
	EXPECT_EQ(-1, v[1]);
	EXPECT_EQ(-1, v[2]);
}

TEST(FillN, Partial)
{
	std::vector<int> v = { 1, 2, 3 };
	auto result = stx::FillN(v.begin(), 2, -1);

	EXPECT_EQ(v.begin() + 2, result);
	EXPECT_EQ(-1, v[0]);
	EXPECT_EQ(-1, v[1]);
	EXPECT_EQ(3, v[2]);
}

