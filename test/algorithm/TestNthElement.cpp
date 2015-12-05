#include <stx/algorithm/NthElement.h>
#include <gtest/gtest.h>
#include <vector>

TEST(NthElement, Empty)
{
	std::vector<int> v;

	stx::NthElement(v.begin(), v.begin(), v.end());

	EXPECT_TRUE(v.empty());
}

TEST(NthElement, One)
{
	std::vector<int> v = { 1 };

	stx::NthElement(v.begin(), v.begin(), v.end());

	EXPECT_EQ(1, v[0]);
}

TEST(NthElement, TwoSorted)
{
	std::vector<int> v = { 1, 2 };

	stx::NthElement(v.begin(), v.begin(), v.end());

	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
}

TEST(NthElement, TwoSortedSecond)
{
	std::vector<int> v = { 1, 2 };

	stx::NthElement(v.begin(), v.begin() + 1, v.end());

	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
}

TEST(NthElement, TwoReverse)
{
	std::vector<int> v = { 2, 1 };

	stx::NthElement(v.begin(), v.begin(), v.end());

	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
}

TEST(NthElement, TwoReverseSecond)
{
	std::vector<int> v = { 2, 1 };

	stx::NthElement(v.begin(), v.begin() + 1, v.end());

	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
}

#include <iostream>

template<typename C>
void Print(const C& c) {
	for (auto& x : c) {
		std::cout << x << ", ";
	}
	std::cout << std::endl;
}

TEST(NthElement, Basic)
{
	std::vector<int> v = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	
	Print(v);
	stx::NthElement(v.begin(), v.begin() + 3, v.end());
	Print(v);

	EXPECT_EQ(4, v[3]);
	EXPECT_LT(v[0], 4);
	EXPECT_LT(v[1], 4);
	EXPECT_LT(v[2], 4);
	EXPECT_GT(4, v[4]);
	EXPECT_GT(4, v[5]);
	EXPECT_GT(4, v[6]);
	EXPECT_GT(4, v[7]);
	EXPECT_GT(4, v[8]);
}

