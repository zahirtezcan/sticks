#include <stx/algorithm/Replace.h>
#include <gtest/gtest.h>
#include <vector>

TEST(Replace, Empty)
{
	std::vector<int> v;
	stx::Replace(v.begin(), v.end(), [](int x) { return x == 0; }, 42);

	EXPECT_TRUE(v.empty());
}

TEST(Replace, Basic)
{
	std::vector<int> v = { 3, 2, 1, 0 };
	stx::Replace(v.begin(), v.end(), [](int x) { return x == 0; }, 42);

	EXPECT_EQ(42, v[3]);
}

TEST(Replace, Multiple)
{
	std::vector<int> v = { 3, 0, 2, 0, 1, 0 };
	stx::Replace(v.begin(), v.end(), [](int x) { return x == 0; }, 42);

	EXPECT_EQ(42, v[1]);
	EXPECT_EQ(42, v[3]);
	EXPECT_EQ(42, v[5]);
}

TEST(ReplaceValue, Empty)
{
	std::vector<int> v;
	stx::ReplaceValue(v.begin(), v.end(), 0, 42);

	EXPECT_TRUE(v.empty());
}

TEST(ReplaceValue, Basic)
{
	std::vector<int> v = { 3, 2, 1, 0 };
	stx::ReplaceValue(v.begin(), v.end(), 0, 42);

	EXPECT_EQ(42, v[3]);
}

TEST(ReplaceValue, Multiple)
{
	std::vector<int> v = { 3, 0, 2, 0, 1, 0 };
	stx::ReplaceValue(v.begin(), v.end(), 0, 42);

	EXPECT_EQ(42, v[1]);
	EXPECT_EQ(42, v[3]);
	EXPECT_EQ(42, v[5]);
}

