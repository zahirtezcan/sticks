#include <stx/algorithm/BinarySearch.h>
#include <gtest/gtest.h>
#include <vector>

TEST(LowerBound, Empty)
{
	std::vector<int> v;
	auto result = stx::LowerBound(v.begin(), v.end(), 3);

	EXPECT_EQ(v.end(), result);
}

TEST(LowerBound, Basic)
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	auto result = stx::LowerBound(v.begin(), v.end(), 3);

	EXPECT_EQ(v.begin() + 2, result);
}

TEST(LowerBound, BasicSingle)
{
	std::vector<int> v = { 1 };
	auto result = stx::LowerBound(v.begin(), v.end(), 1);

	EXPECT_EQ(v.begin(), result);
}

TEST(LowerBound, LessSingle)
{
	std::vector<int> v = { 2 };
	auto result = stx::LowerBound(v.begin(), v.end(), 1);

	EXPECT_EQ(v.begin(), result);
}

TEST(LowerBound, GreaterSingle)
{
	std::vector<int> v = { 0 };
	auto result = stx::LowerBound(v.begin(), v.end(), 1);

	EXPECT_EQ(v.end(), result);
}

TEST(UpperBound, Empty)
{
	std::vector<int> v;
	auto result = stx::UpperBound(v.begin(), v.end(), 3);

	EXPECT_EQ(v.end(), result);
}

TEST(UpperBound, Basic)
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	auto result = stx::UpperBound(v.begin(), v.end(), 3);

	EXPECT_EQ(v.begin() + 3, result);
}

TEST(UpperBound, BasicSingle)
{
	std::vector<int> v = { 1 };
	auto result = stx::UpperBound(v.begin(), v.end(), 1);

	EXPECT_EQ(v.end(), result);
}

TEST(UpperBound, LessSingle)
{
	std::vector<int> v = { 2 };
	auto result = stx::UpperBound(v.begin(), v.end(), 1);

	EXPECT_EQ(v.begin(), result);
}

TEST(UpperBound, GreaterSingle)
{
	std::vector<int> v = { 0 };
	auto result = stx::UpperBound(v.begin(), v.end(), 1);

	EXPECT_EQ(v.end(), result);
}

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

