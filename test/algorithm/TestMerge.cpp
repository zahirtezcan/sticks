#include <stx/algorithm/Merge.h>
#include <gtest/gtest.h>
#include <vector>
#include <iterator>

TEST(Merge, Empty)
{
	std::vector<int> v;
	std::vector<int> u;
	std::vector<int> o;

	stx::Merge(v.begin(), v.end(), u.begin(), u.end(),
	           std::back_inserter(o));
	EXPECT_TRUE(o.empty());
}

TEST(Merge, EmptyFirst)
{
	std::vector<int> v;
	std::vector<int> u = { 1 };
	std::vector<int> o;

	stx::Merge(v.begin(), v.end(), u.begin(), u.end(),
	           std::back_inserter(o));

	EXPECT_EQ(std::vector<int>::size_type(1), o.size());
	EXPECT_EQ(1, o[0]);
}

TEST(Merge, EmptySecond)
{
	std::vector<int> v = { 1 };
	std::vector<int> u;
	std::vector<int> o;

	stx::Merge(v.begin(), v.end(), u.begin(), u.end(),
	           std::back_inserter(o));

	EXPECT_EQ(std::vector<int>::size_type(1), o.size());
	EXPECT_EQ(1, o[0]);
}

TEST(Merge, Basic)
{
	std::vector<int> v = { 1, 3, 5 };
	std::vector<int> u = { 2, 4, 6 };
	std::vector<int> o;

	stx::Merge(v.begin(), v.end(), u.begin(), u.end(),
	           std::back_inserter(o));

	EXPECT_EQ(std::vector<int>::size_type(6), o.size());
	EXPECT_EQ(1, o[0]);
	EXPECT_EQ(2, o[1]);
	EXPECT_EQ(3, o[2]);
	EXPECT_EQ(4, o[3]);
	EXPECT_EQ(5, o[4]);
	EXPECT_EQ(6, o[5]);
}

