#include <stx/algorithm/Fill.h>
#include <gtest/gtest.h>
#include <vector>

TEST(Fill, Empty)
{
	std::vector<int> v;
	stx::Fill(v.begin(), v.end(), -1);

	EXPECT_TRUE(v.empty());
}

TEST(Fill, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	stx::Fill(v.begin(), v.end(), -1);

	EXPECT_EQ(-1, v[0]);
	EXPECT_EQ(-1, v[1]);
	EXPECT_EQ(-1, v[2]);
}

TEST(Fill, Partial)
{
	std::vector<int> v = { 1, 2, 3 };
	stx::Fill(v.begin(), v.begin() + 2, -1);

	EXPECT_EQ(-1, v[0]);
	EXPECT_EQ(-1, v[1]);
	EXPECT_EQ(3, v[2]);
}

