#include <stx/algorithm/EqualRange.h>
#include <gtest/gtest.h>
#include <vector>

TEST(EqualRange, Empty)
{
	std::vector<int> v;
	auto result = stx::EqualRange(v.begin(), v.end(), 0);
	
	EXPECT_EQ(v.end(), result.first);
	EXPECT_EQ(v.end(), result.second);
}

TEST(EqualRange, NoElementMin)
{
	std::vector<int> v = { 1, 2, 3 };
	auto result = stx::EqualRange(v.begin(), v.end(), 0);
	
	EXPECT_EQ(v.begin(), result.first);
	EXPECT_EQ(v.begin(), result.second);
}

TEST(EqualRange, NoElementMax)
{
	std::vector<int> v = { 1, 2, 3 };
	auto result = stx::EqualRange(v.begin(), v.end(), 999);
	
	EXPECT_EQ(v.end(), result.first);
	EXPECT_EQ(v.end(), result.second);
}

TEST(EqualRange, LastElement)
{
	std::vector<int> v = { 1, 2, 3 };
	auto result = stx::EqualRange(v.begin(), v.end(), 3);
	
	EXPECT_EQ(v.end() - 1, result.first);
	EXPECT_EQ(v.end(), result.second);
}

TEST(EqualRange, EqualElements)
{
	std::vector<int> v = { 1, 2, 2, 3 };
	auto result = stx::EqualRange(v.begin(), v.end(), 2);
	
	EXPECT_EQ(v.begin() + 1, result.first);
	EXPECT_EQ(v.begin() + 3, result.second);
}

