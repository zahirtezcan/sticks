#include <stx/algorithm/SortedIntersection.h>
#include <gtest/gtest.h>
#include <vector>
#include <iterator>

TEST(SortedIntersection, Empty)
{
	std::vector<int> v;
	std::vector<int> u;
	std::vector<int> o;

	stx::SortedIntersection(v.begin(), v.end(), u.begin(), u.end(),
	                        std::back_inserter(o));
	EXPECT_TRUE(o.empty());
}

TEST(SortedIntersection, EmptyFirst)
{
	std::vector<int> v;
	std::vector<int> u = { 1, 3, 5 };
	std::vector<int> o;

	stx::SortedIntersection(v.begin(), v.end(), u.begin(), u.end(),
	                        std::back_inserter(o));
	EXPECT_TRUE(o.empty());
}

TEST(SortedIntersection, EmptySecond)
{
	std::vector<int> v = { 2, 4, 6 };
	std::vector<int> u;
	std::vector<int> o;

	stx::SortedIntersection(v.begin(), v.end(), u.begin(), u.end(),
	                        std::back_inserter(o));
	EXPECT_TRUE(o.empty());
}

TEST(SortedIntersection, Basic)
{
	std::vector<int> v = { 1, 2, 3, 4, 5, 6 };
	std::vector<int> u = { 1, 3, 5 };
	std::vector<int> o;

	stx::SortedIntersection(v.begin(), v.end(), u.begin(), u.end(),
	                        std::back_inserter(o));
	
	EXPECT_EQ(std::vector<int>::size_type(3), o.size());
	EXPECT_EQ(1, o[0]);
	EXPECT_EQ(3, o[1]);
	EXPECT_EQ(5, o[2]);
}

