#include <stx/algorithm/BinarySearch.h>
#include <gtest/gtest.h>
#include <vector>

TEST(BinarySearch, Empty)
{
	std::vector<int> v;
	auto result = stx::BinarySearch(v.begin(), v.end(), 3);

	EXPECT_FALSE(result);
}

TEST(BinarySearch, Basic)
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	auto result = stx::BinarySearch(v.begin(), v.end(), 3);

	EXPECT_TRUE(result);
}

TEST(BinarySearch, BasicSingle)
{
	std::vector<int> v = { 1 };
	auto result = stx::BinarySearch(v.begin(), v.end(), 1);

	EXPECT_TRUE(result);
}

TEST(BinarySearch, LessSingle)
{
	std::vector<int> v = { 2 };
	auto result = stx::BinarySearch(v.begin(), v.end(), 1);

	EXPECT_FALSE(result);
}

TEST(BinarySearch, GreaterSingle)
{
	std::vector<int> v = { 0 };
	auto result = stx::BinarySearch(v.begin(), v.end(), 1);

	EXPECT_FALSE(result);
}

