#include <stx/algorithm/SortedIncludes.h>
#include <gtest/gtest.h>
#include <vector>

TEST(SortedIncludes, Empty)
{
	std::vector<int> v;
	std::vector<int> u;

	bool inc = stx::SortedIncludes(v.begin(), v.end(), u.begin(), u.end());

	EXPECT_TRUE(inc);
}

TEST(SortedIncludes, EmptyFirst)
{
	std::vector<int> v;
	std::vector<int> u = { 1 };

	bool inc = stx::SortedIncludes(v.begin(), v.end(), u.begin(), u.end());

	EXPECT_FALSE(inc);
}

TEST(SortedIncludes, EmptySecond)
{
	std::vector<int> v = { 1 };
	std::vector<int> u;

	bool inc = stx::SortedIncludes(v.begin(), v.end(), u.begin(), u.end());

	EXPECT_TRUE(inc);
}

TEST(SortedIncludes, Basic)
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	std::vector<int> u = { 2, 4 };

	bool inc = stx::SortedIncludes(v.begin(), v.end(), u.begin(), u.end());

	EXPECT_TRUE(inc);
}

TEST(SortedIncludes, BasicFalse)
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	std::vector<int> u = { 2, 6 };

	bool inc = stx::SortedIncludes(v.begin(), v.end(), u.begin(), u.end());

	EXPECT_FALSE(inc);
}

TEST(SortedIncludes, RepeatedElements)
{
	std::vector<int> v = { 1, 2, 2, 3, 4, 5 };
	std::vector<int> u = { 2, 2, 4 };

	bool inc = stx::SortedIncludes(v.begin(), v.end(), u.begin(), u.end());

	EXPECT_TRUE(inc);
}

TEST(SortedIncludes, NonRepeatedElements)
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	std::vector<int> u = { 2, 2, 4 };

	bool inc = stx::SortedIncludes(v.begin(), v.end(), u.begin(), u.end());

	EXPECT_FALSE(inc);
}

