#include <stx/algorithm/StableSortInplace.h>
#include <gtest/gtest.h>
#include <vector>
#include <stx/algorithm/Sort.h>

TEST(StableSortInplace, Empty)
{
	std::vector<int> v;

	stx::StableSortInplace(v.begin(), v.end());
	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(StableSortInplace, One)
{
	std::vector<int> v = { 1 };

	stx::StableSortInplace(v.begin(), v.end());
	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(StableSortInplace, Two)
{
	std::vector<int> v = { 2, 1 };

	EXPECT_FALSE(stx::IsSorted(v.begin(), v.end()));
	stx::StableSortInplace(v.begin(), v.end());
	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(StableSortInplace, TwoSorted)
{
	std::vector<int> v = { 1, 2 };

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
	stx::StableSortInplace(v.begin(), v.end());
	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(StableSortInplace, Basic)
{
	std::vector<int> v = { 2, 4, 1, 5, 3 };

	EXPECT_FALSE(stx::IsSorted(v.begin(), v.end()));
	stx::StableSortInplace(v.begin(), v.end());
	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(StableSortInplace, BasicSorted)
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
	stx::StableSortInplace(v.begin(), v.end());
	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(StableSortInplace, Stability)
{
	std::vector<std::pair<int, int>> v;
	for (int i = 1; i < 36; ++i)
	{
		v.push_back({ i % 5, i % 2 });
	}

	auto secondLess = [] (auto x, auto y) { return x.second < y.second; };
	auto firstLess = [] (auto x, auto y) { return x.first < y.first; };

	EXPECT_FALSE(stx::IsSorted(v.begin(), v.end(), firstLess));
	EXPECT_FALSE(stx::IsSorted(v.begin(), v.end(), secondLess));

	stx::StableSortInplace(v.begin(), v.end(), secondLess);

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end(), secondLess));

	stx::StableSortInplace(v.begin(), v.end(), firstLess);

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end(), firstLess));

	for (size_t i = 0; i < v.size() - 1; ++i)
	{
		EXPECT_TRUE(v[i].first < v[i + 1].first || v[i].second <= v[i + 1].second)
			<< "i: " << i
			<< ", v[i].first: " << v[i].first
			<< ", v[i + 1].first: " << v[i + 1].first
			<< ", v[i].second: " << v[i].second
			<< ", v[i + 1].second: " << v[i + 1].second; 
	}
}

