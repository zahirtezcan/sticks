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

#include <algorithm>

TEST(NextPermutation, FiveElements)
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	std::vector<int> u = v;
	int count = 1;
	while (stx::NextPermutation(u.begin(), u.end())) {
		auto isPerm = std::is_permutation(u.begin(), u.end(),
		                                  v.begin());
		EXPECT_TRUE(isPerm);
		++count;
	}

	EXPECT_EQ(120, count);// 120 = 5!
	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(3, v[2]);
	EXPECT_EQ(4, v[3]);
	EXPECT_EQ(5, v[4]);

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

#include <algorithm>

TEST(PreviousPermutation, FiveElements)
{
	std::vector<int> v = { 5, 4, 3, 2, 1 };
	std::vector<int> u = v;
	int count = 1;
	while (stx::PreviousPermutation(u.begin(), u.end())) {
		auto isPerm = std::is_permutation(u.begin(), u.end(),
		                                  v.begin());
		EXPECT_TRUE(isPerm);
		++count;
	}

	EXPECT_EQ(120, count);// 120 = 5!
	EXPECT_EQ(5, v[0]);
	EXPECT_EQ(4, v[1]);
	EXPECT_EQ(3, v[2]);
	EXPECT_EQ(2, v[3]);
	EXPECT_EQ(1, v[4]);

}
