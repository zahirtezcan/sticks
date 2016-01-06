#include <stx/algorithm/FindLastSequence.h>
#include <gtest/gtest.h>
#include <vector>

TEST(FindLastSequence, Empty)
{
	std::vector<int> v;
	std::vector<int> t = { 2, 3, 4 };

	auto result = stx::FindLastSequence(v.begin(), v.end(), t.begin(), t.end());

	EXPECT_EQ(v.end(), result);
}

TEST(FindLastSequence, NoValue)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> t;

	auto result = stx::FindLastSequence(v.begin(), v.end(), t.begin(), t.end());

	EXPECT_EQ(v.end(), result);
}

TEST(FindLastSequence, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> t = { 2, 3 };

	auto result = stx::FindLastSequence(v.begin(), v.end(), t.begin(), t.end());

	EXPECT_EQ(v.begin() + 1, result);
}

TEST(FindLastSequence, Duplicate)
{
	std::vector<int> v = { 1, 2, 3, 2, 3 };
	std::vector<int> t = { 2, 3 };

	auto result = stx::FindLastSequence(v.begin(), v.end(), t.begin(), t.end());

	EXPECT_EQ(v.begin() + 3, result);
}

