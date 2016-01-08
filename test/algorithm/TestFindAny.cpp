#include <stx/algorithm/FindAny.h>
#include <gtest/gtest.h>
#include <vector>

TEST(FindAny, Empty)
{
	std::vector<int> v;
	std::vector<int> t = { 2, 3, 4 };

	auto result = stx::FindAny(v.begin(), v.end(), t.begin(), t.end());

	EXPECT_EQ(v.end(), result);
}

TEST(FindAny, NoValue)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> t;

	auto result = stx::FindAny(v.begin(), v.end(), t.begin(), t.end());

	EXPECT_EQ(v.end(), result);
}

TEST(FindAny, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> t = { 2, 3, 4 };

	auto result = stx::FindAny(v.begin(), v.end(), t.begin(), t.end());

	EXPECT_EQ(v.begin() + 1, result);
}

TEST(FindAnyPredicate, Empty)
{
	std::vector<int> v;
	std::vector<int> t = { 2, 3, 4 };

	auto result = stx::FindAny(v.begin(), v.end(), t.begin(), t.end(), [] (int, int) { return true; });

	EXPECT_EQ(v.end(), result);
}

TEST(FindAnyPredicate, NoValue)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> t;

	auto result = stx::FindAny(v.begin(), v.end(), t.begin(), t.end(), [] (int, int) { return true; });

	EXPECT_EQ(v.end(), result);
}

TEST(FindAnyPredicate, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> t = { 2, 3, 4 };

	auto result = stx::FindAny(v.begin(), v.end(), t.begin(), t.end(), [] (int x, int y) { return x == y; });

	EXPECT_EQ(v.begin() + 1, result);
}

