#include <stx/algorithm/SwapRanges.h>
#include <gtest/gtest.h>
#include <vector>

TEST(SwapRanges, Empty)
{
	std::vector<int> v,y;
	auto result = stx::SwapRanges(v.begin(), v.end(), y.begin(), y.end());

	EXPECT_EQ(v.end(), result.first);
	EXPECT_EQ(y.end(), result.second);
}

TEST(SwapRanges, EmptyFirst)
{
	std::vector<int> v;
	std::vector<int> y = {1};
	auto result = stx::SwapRanges(v.begin(), v.end(), y.begin(), y.end());

	EXPECT_EQ(v.end(), result.first);
	EXPECT_EQ(y.begin(), result.second);
}

TEST(SwapRanges, EmptySecond)
{
	std::vector<int> v = {1};
	std::vector<int> y;
	auto result = stx::SwapRanges(v.begin(), v.end(), y.begin(), y.end());

	EXPECT_EQ(v.begin(), result.first);
	EXPECT_EQ(y.end(), result.second);
}

TEST(SwapRanges, Basic)
{
	std::vector<int> v = {1, 2, 3};
	std::vector<int> y = {4, 5, 6};
	auto result = stx::SwapRanges(v.begin(), v.end(), y.begin(), y.end());

	EXPECT_EQ(v.end(), result.first);
	EXPECT_EQ(y.end(), result.second);
	EXPECT_EQ(1, y[0]);
	EXPECT_EQ(2, y[1]);
	EXPECT_EQ(3, y[2]);
	EXPECT_EQ(4, v[0]);
	EXPECT_EQ(5, v[1]);
	EXPECT_EQ(6, v[2]);
}

TEST(SwapRanges, NonEqualLength)
{
	std::vector<int> v = {1, 2, 3};
	std::vector<int> y = {4, 5};
	auto result = stx::SwapRanges(v.begin(), v.end(), y.begin(), y.end());

	EXPECT_EQ(v.begin() + y.size(), result.first);
	EXPECT_EQ(y.end(), result.second);
	EXPECT_EQ(1, y[0]);
	EXPECT_EQ(2, y[1]);
	EXPECT_EQ(4, v[0]);
	EXPECT_EQ(5, v[1]);
	EXPECT_EQ(3, v[2]);
}
