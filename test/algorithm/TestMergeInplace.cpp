#include <stx/algorithm/MergeInplace.h>
#include <stx/algorithm/Sort.h>
#include <gtest/gtest.h>
#include <vector>

TEST(MergeInplace, Empty)
{
	std::vector<int> v;

	stx::MergeInplace(v.begin(), v.end(), v.end());

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(MergeInplace, One)
{
	std::vector<int> v = { 1 };

	stx::MergeInplace(v.begin(), v.end(), v.end());

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(MergeInplace, TwoSorted)
{
	std::vector<int> v = { 1, 2 };

	stx::MergeInplace(v.begin(), v.begin() + 1, v.end());

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(MergeInplace, TwoReversed)
{
	std::vector<int> v = { 2, 1 };

	stx::MergeInplace(v.begin(), v.begin() + 1, v.end());

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(MergeInplace, Basic)
{
	std::vector<int> v = { 2, 4, 6, 8, 1, 3, 5, 7 };

	stx::MergeInplace(v.begin(), v.begin() + 4, v.end());

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

TEST(MergeInplace, BasicAsymmetric)
{
	std::vector<int> v = { 4, 6, 8, 1, 3, 5, 7 };

	stx::MergeInplace(v.begin(), v.begin() + 3, v.end());

	EXPECT_TRUE(stx::IsSorted(v.begin(), v.end()));
}

