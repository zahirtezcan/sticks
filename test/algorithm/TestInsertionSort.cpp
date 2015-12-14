#include <stx/algorithm/InsertionSort.h>
#include <gtest/gtest.h>
#include <vector>
#include <stx/algorithm/Sort.h>

TEST(InsertionSort, Empty)
{
	std::vector<int> v;

	stx::InsertionSort(v.begin(), v.end());
	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(InsertionSort, One)
{
	std::vector<int> v = { 1 };

	stx::InsertionSort(v.begin(), v.end());
	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(InsertionSort, Two)
{
	std::vector<int> v = { 2, 1 };

	EXPECT_FALSE(stx::IsSorted(v.begin(), v.end()));
	stx::InsertionSort(v.begin(), v.end());
	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(InsertionSort, TwoSorted)
{
	std::vector<int> v = { 1, 2 };

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
	stx::InsertionSort(v.begin(), v.end());
	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(InsertionSort, Basic)
{
	std::vector<int> v = { 2, 4, 1, 5, 3 };

	EXPECT_FALSE(stx::IsSorted(v.begin(), v.end()));
	stx::InsertionSort(v.begin(), v.end());
	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(InsertionSort, BasicSorted)
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
	stx::InsertionSort(v.begin(), v.end());
	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(InsertionSort, Stability)
{
	std::vector<std::pair<int, int>> v = { { 4, 1 }, { 4, 2 },
	                                       { 2, 2 }, { 2, 1 },
					       { 3, 2 }, { 3, 1 } };

	auto secondLess = [] (auto x, auto y) { return x.second < y.second; };
	auto firstLess = [] (auto x, auto y) { return x.first < y.first; };

	EXPECT_FALSE(stx::IsSorted(v.begin(), v.end(), firstLess));
	EXPECT_FALSE(stx::IsSorted(v.begin(), v.end(), secondLess));

	stx::InsertionSort(v.begin(), v.end(), secondLess);

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end(), secondLess));

	stx::InsertionSort(v.begin(), v.end(), firstLess);

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end(), firstLess));

	for (size_t i = 0; i < v.size() - 1; ++i)
	{
		EXPECT_TRUE(v[i].first < v[i + 1].first || v[i].second <= v[i + 1].second); 
	}
}

