#include <stx/algorithm/LowerBound.h>
#include <gtest/gtest.h>
#include <vector>

TEST(LowerBound, Empty)
{
	std::vector<int> v;
	auto result = stx::LowerBound(v.begin(), v.end(), 3);

	EXPECT_EQ(v.end(), result);
}

TEST(LowerBound, Basic)
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	auto result = stx::LowerBound(v.begin(), v.end(), 3);

	EXPECT_EQ(v.begin() + 2, result);
}

TEST(LowerBound, BasicSingle)
{
	std::vector<int> v = { 1 };
	auto result = stx::LowerBound(v.begin(), v.end(), 1);

	EXPECT_EQ(v.begin(), result);
}

TEST(LowerBound, LessSingle)
{
	std::vector<int> v = { 2 };
	auto result = stx::LowerBound(v.begin(), v.end(), 1);

	EXPECT_EQ(v.begin(), result);
}

TEST(LowerBound, GreaterSingle)
{
	std::vector<int> v = { 0 };
	auto result = stx::LowerBound(v.begin(), v.end(), 1);

	EXPECT_EQ(v.end(), result);
}

