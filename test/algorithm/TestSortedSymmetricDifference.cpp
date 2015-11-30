#include <stx/algorithm/SortedSymmetricDifference.h>
#include <gtest/gtest.h>
#include <vector>
#include <iterator>

TEST(SortedSymmetricDifference, Empty)
{
	std::vector<int> v;
	std::vector<int> u;
	std::vector<int> o;

	stx::SortedSymmetricDifference(v.begin(), v.end(), u.begin(), u.end(),
	                               std::back_inserter(o));

	EXPECT_TRUE(o.empty());
}

TEST(SortedSymmetricDifference, EmptyFirst)
{
	std::vector<int> v;
	std::vector<int> u = { 1, 3, 5 };
	std::vector<int> o;

	stx::SortedSymmetricDifference(v.begin(), v.end(), u.begin(), u.end(),
	                               std::back_inserter(o));

	EXPECT_EQ(u.size(), o.size());
	EXPECT_EQ(1, o[0]);
	EXPECT_EQ(3, o[1]);
	EXPECT_EQ(5, o[2]);

}

TEST(SortedSymmetricDifference, EmptySecond)
{
	std::vector<int> v = { 2, 4, 6 };
	std::vector<int> u;
	std::vector<int> o;

	stx::SortedSymmetricDifference(v.begin(), v.end(), u.begin(), u.end(),
	                               std::back_inserter(o));

	EXPECT_EQ(v.size(), o.size());
	EXPECT_EQ(2, o[0]);
	EXPECT_EQ(4, o[1]);
	EXPECT_EQ(6, o[2]);
}

TEST(SortedSymmetricDifference, Basic)
{
	std::vector<int> v = { 1, 2, 3, 4 };
	std::vector<int> u = { 2, 3, 5 };
	std::vector<int> o;

	stx::SortedSymmetricDifference(v.begin(), v.end(), u.begin(), u.end(),
	                               std::back_inserter(o));
	
	EXPECT_EQ(std::vector<int>::size_type(3), o.size());
	EXPECT_EQ(1, o[0]);
	EXPECT_EQ(4, o[1]);
	EXPECT_EQ(5, o[2]);
}

