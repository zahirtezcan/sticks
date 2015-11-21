#include <stx/algorithm/MinMax.h>
#include <gtest/gtest.h>
#include <vector>

TEST(Min, BasicFirst)
{
	int x = 0;
	auto& result = stx::Min(x, 1);

	EXPECT_EQ(0, result);
	EXPECT_EQ(&x, &result);
}

TEST(Min, BasicSecond)
{
	int x = 0;
	auto& result = stx::Min(1, x);

	EXPECT_EQ(0, result);
	EXPECT_EQ(&x, &result);
}

TEST(Min, Stable)
{
	int x = 0;
	int y = 0;
	auto& result = stx::Min(x, y);

	EXPECT_EQ(0, result);
	EXPECT_EQ(&x, &result);
}

TEST(Max, BasicFirst)
{
	int x = 0;
	auto& result = stx::Max(x, -1);

	EXPECT_EQ(0, result);
	EXPECT_EQ(&x, &result);
}

TEST(Max, BasicSecond)
{
	int x = 0;
	auto& result = stx::Max(-1, x);

	EXPECT_EQ(0, result);
	EXPECT_EQ(&x, &result);
}

TEST(Max, Stable)
{
	int x = 0;
	int y = 0;
	auto& result = stx::Max(x, y);

	EXPECT_EQ(0, result);
	EXPECT_EQ(&x, &result);
}

TEST(MinElement, Empty)
{
	std::vector<int> v;
	auto result = stx::MinElement(v.begin(), v.end());

	EXPECT_EQ(v.end(), result);
}

TEST(MinElement, Basic)
{
	std::vector<int> v = { 1, 2, 1, 3 };
	auto result = stx::MinElement(v.begin(), v.end());

	EXPECT_EQ(v.begin(), result);
}

TEST(MaxElement, Empty)
{
	std::vector<int> v;
	auto result = stx::MaxElement(v.begin(), v.end());

	EXPECT_EQ(v.end(), result);
}

TEST(MaxElement, Basic)
{
	std::vector<int> v = { 1, 2, 3, 3 };
	auto result = stx::MaxElement(v.begin(), v.end());

	EXPECT_EQ(v.end() - 2, result);
}


