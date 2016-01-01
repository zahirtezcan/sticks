#include <stx/algorithm/UpperBound.h>
#include <gtest/gtest.h>
#include <vector>

TEST(UpperBound, Empty)
{
	std::vector<int> v;
	auto result = stx::UpperBound(v.begin(), v.end(), 3);

	EXPECT_EQ(v.end(), result);
}

TEST(UpperBound, Basic)
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	auto result = stx::UpperBound(v.begin(), v.end(), 3);

	EXPECT_EQ(v.begin() + 3, result);
}

TEST(UpperBound, BasicSingle)
{
	std::vector<int> v = { 1 };
	auto result = stx::UpperBound(v.begin(), v.end(), 1);

	EXPECT_EQ(v.end(), result);
}

TEST(UpperBound, LessSingle)
{
	std::vector<int> v = { 2 };
	auto result = stx::UpperBound(v.begin(), v.end(), 1);

	EXPECT_EQ(v.begin(), result);
}

TEST(UpperBound, GreaterSingle)
{
	std::vector<int> v = { 0 };
	auto result = stx::UpperBound(v.begin(), v.end(), 1);

	EXPECT_EQ(v.end(), result);
}

