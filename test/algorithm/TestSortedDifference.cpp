#include <stx/algorithm/SortedDifference.h>
#include <gtest/gtest.h>
#include <vector>
#include <iterator>

TEST(SortedDifference, Empty)
{
	std::vector<int> v;
	std::vector<int> u;
	std::vector<int> o;

	stx::SortedDifference(v.begin(), v.end(), u.begin(), u.end(),
	                      std::back_inserter(o));
	EXPECT_TRUE(o.empty());
}

TEST(SortedDifference, EmptyFirst)
{
	std::vector<int> v;
	std::vector<int> u = { 1, 3, 5 };
	std::vector<int> o;

	stx::SortedDifference(v.begin(), v.end(), u.begin(), u.end(),
	                      std::back_inserter(o));
	EXPECT_TRUE(o.empty());
}

TEST(SortedDifference, EmptySecond)
{
	std::vector<int> v = { 2, 4, 6 };
	std::vector<int> u;
	std::vector<int> o;

	stx::SortedDifference(v.begin(), v.end(), u.begin(), u.end(),
	                      std::back_inserter(o));
	EXPECT_EQ(v.size(), o.size());
	EXPECT_EQ(2, o[0]);
	EXPECT_EQ(4, o[1]);
	EXPECT_EQ(6, o[2]);
}

TEST(SortedDifference, Basic)
{
	std::vector<int> v = { 1, 2, 3, 4, 5, 6 };
	std::vector<int> u = { 1, 3, 5 };
	std::vector<int> o;

	stx::SortedDifference(v.begin(), v.end(), u.begin(), u.end(),
	                      std::back_inserter(o));
	EXPECT_EQ(v.size() - u.size(), o.size());
	EXPECT_EQ(2, o[0]);
	EXPECT_EQ(4, o[1]);
	EXPECT_EQ(6, o[2]);
}



