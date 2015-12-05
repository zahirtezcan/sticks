#include <stx/algorithm/Sort.h>
#include <gtest/gtest.h>
#include <vector>
#include <stx/algorithm/MinMax.h>

TEST(FindSortedEnd, Empty)
{
	std::vector<int> v;
	
	auto result = stx::FindSortedEnd(v.begin(), v.end());

	EXPECT_EQ(v.end(), result);
}

TEST(FindSortedEnd, One)
{
	std::vector<int> v = { 1 };
	
	auto result = stx::FindSortedEnd(v.begin(), v.end());

	EXPECT_EQ(v.end(), result);
}

TEST(FindSortedEnd, Two)
{
	std::vector<int> v = { 1, 2 };
	
	auto result = stx::FindSortedEnd(v.begin(), v.end());

	EXPECT_EQ(v.end(), result);
}

TEST(FindSortedEnd, TwoFalse)
{
	std::vector<int> v = { 1, 0 };
	
	auto result = stx::FindSortedEnd(v.begin(), v.end());

	EXPECT_EQ(v.begin() + 1, result);
}

TEST(FindSortedEnd, Basic)
{
	std::vector<int> v = { 1, 2, 2, 3, 4, 5 };
	
	auto result = stx::FindSortedEnd(v.begin(), v.end());

	EXPECT_EQ(v.end(), result);
}

TEST(FindSortedEnd, BasicFalse)
{
	std::vector<int> v = { 1, 2, 3, 2, 5 };
	
	auto result = stx::FindSortedEnd(v.begin(), v.end());

	EXPECT_EQ(v.begin() + 3, result);
}

TEST(IsSorted, Empty)
{
	std::vector<int> v;
	
	bool result = stx::IsSorted(v.begin(), v.end());

	EXPECT_TRUE(result);
}

TEST(IsSorted, One)
{
	std::vector<int> v = { 1 };
	
	bool result = stx::IsSorted(v.begin(), v.end());

	EXPECT_TRUE(result);
}

TEST(IsSorted, Basic)
{
	std::vector<int> v = { 1, 2, 2, 3, 4, 5 };
	
	bool result = stx::IsSorted(v.begin(), v.end());

	EXPECT_TRUE(result);
}

TEST(IsSorted, BasicFalse)
{
	std::vector<int> v = { 1, 2, 3, 2, 5 };
	
	bool result = stx::IsSorted(v.begin(), v.end());

	EXPECT_FALSE(result);
}

