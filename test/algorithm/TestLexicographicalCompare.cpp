#include <stx/algorithm/LexicographicalCompare.h>
#include <gtest/gtest.h>
#include <vector>

TEST(LexicographicalCompare, Empty)
{
	std::vector<int> u,v;
	auto result = stx::LexicographicalCompare(u.begin(), u.end(),
	                                          v.begin(), v.end());
	EXPECT_FALSE(result);
}

TEST(LexicographicalCompare, BasicTrue)
{
	std::vector<int> u = { 1, 2, 3 };
	std::vector<int> v = { 1, 2, 4 };
	auto result = stx::LexicographicalCompare(u.begin(), u.end(),
	                                          v.begin(), v.end());
	EXPECT_TRUE(result);
}

TEST(LexicographicalCompare, BasicFalse)
{
	std::vector<int> u = { 1, 2, 3 };
	std::vector<int> v = { 1, 2, -1 };
	auto result = stx::LexicographicalCompare(u.begin(), u.end(),
	                                          v.begin(), v.end());
	EXPECT_FALSE(result);
}

TEST(LexicographicalCompare, Equal)
{
	std::vector<int> u = { 1, 2, 3 };
	std::vector<int> v = { 1, 2, 3 };
	auto result = stx::LexicographicalCompare(u.begin(), u.end(),
	                                          v.begin(), v.end());
	EXPECT_FALSE(result);
}

TEST(LexicographicalCompare, LengthLess)
{
	std::vector<int> u = { 1, 2, 3 };
	std::vector<int> v = { 1, 2, 3, 4};
	auto result = stx::LexicographicalCompare(u.begin(), u.end(),
	                                          v.begin(), v.end());
	EXPECT_TRUE(result);
}

TEST(LexicographicalCompare, LengthGreater)
{
	std::vector<int> u = { 1, 2, 3, 4};
	std::vector<int> v = { 1, 2, 3 };
	auto result = stx::LexicographicalCompare(u.begin(), u.end(),
	                                          v.begin(), v.end());
	EXPECT_FALSE(result);
}

#include <stx/algorithm/MinMax.h>

TEST(LexicographicallyLess, Basic)
{
	std::vector< std::vector<int> > u;
	u.push_back({ 2, 3 });
	u.push_back({ 1, 2, 3, 4 });
	u.push_back({ 1, 2, 3 });
	auto result = stx::MinElement(u.begin(), u.end(),
	                              stx::LexicographicallyLess<>());
	EXPECT_EQ(u.end() - 1, result);
}
