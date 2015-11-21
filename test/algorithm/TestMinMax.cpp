#include <stx/algorithm/MinMax.h>
#include <gtest/gtest.h>

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



