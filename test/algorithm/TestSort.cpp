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

TEST(Sort, Empty)
{
	std::vector<int> v;
	
	stx::Sort(v.begin(), v.end());

	EXPECT_TRUE(v.empty());
}

TEST(Sort, One)
{
	std::vector<int> v = { 1 };
	
	stx::Sort(v.begin(), v.end());

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(Sort, Basic)
{
	std::vector<int> v = { 5, 4, 3, 2, 2, 1 };
	
	stx::Sort(v.begin(), v.end());

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(Sort, BasicSorted)
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	
	stx::Sort(v.begin(), v.end());

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(PartialSort, Empty)
{
	std::vector<int> v;
	
	stx::PartialSort(v.begin(), v.begin(), v.end());

	EXPECT_TRUE(v.empty());
}

TEST(PartialSort, One)
{
	std::vector<int> v = { 1 };
	
	stx::PartialSort(v.begin(), v.end(), v.end());

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(PartialSort, Basic)
{
	std::vector<int> v = { 5, 4, 3, 2, 2, 1 };
	
	stx::PartialSort(v.begin(), v.begin() + 3, v.end());

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.begin() + 3));
	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(2, v[2]);
}

TEST(PartialSort, BasicSorted)
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	
	stx::PartialSort(v.begin(), v.begin() + 3, v.end());

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.begin() + 3));
	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(3, v[2]);
}

