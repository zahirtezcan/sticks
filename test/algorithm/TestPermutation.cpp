#include <stx/algorithm/Permutation.h>
#include <gtest/gtest.h>
#include <vector>

TEST(NextPermutation, Empty)
{
	std::vector<int> v;

	auto result = stx::NextPermutation(v.begin(), v.end());

	EXPECT_FALSE(result);
}

TEST(NextPermutation, Single)
{
	std::vector<int> v = { 1 };

	auto result = stx::NextPermutation(v.begin(), v.end());

	EXPECT_FALSE(result);
	EXPECT_EQ(1, v[0]);
}

TEST(NextPermutation, Basic)
{
	std::vector<int> v = { 1, 2 };

	auto result = stx::NextPermutation(v.begin(), v.end());

	EXPECT_TRUE(result);
	EXPECT_EQ(2, v[0]);
	EXPECT_EQ(1, v[1]);

	result = stx::NextPermutation(v.begin(), v.end());

	EXPECT_FALSE(result);
	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
}

TEST(PreviousPermutation, Empty)
{
	std::vector<int> v;

	auto result = stx::PreviousPermutation(v.begin(), v.end());

	EXPECT_FALSE(result);
}

TEST(PreviousPermutation, Single)
{
	std::vector<int> v = { 1 };

	auto result = stx::PreviousPermutation(v.begin(), v.end());

	EXPECT_FALSE(result);
	EXPECT_EQ(1, v[0]);
}

TEST(PreviousPermutation, Basic)
{
	std::vector<int> v = { 1, 2 };

	auto result = stx::PreviousPermutation(v.begin(), v.end());

	EXPECT_FALSE(result);
	EXPECT_EQ(2, v[0]);
	EXPECT_EQ(1, v[1]);

	result = stx::PreviousPermutation(v.begin(), v.end());

	EXPECT_TRUE(result);
	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
}

/*TODO: test next permutation with IsPermutation and loop around*/
