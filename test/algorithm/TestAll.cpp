#include <stx/algorithm/All.h>
#include <gtest/gtest.h>

TEST(All, Empty)
{
	int a[] = { 1, 2 ,3 };
	auto result = stx::All(a, a, [](int) { return true; });

	EXPECT_TRUE(result);
}

TEST(All, Dumb)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);

	auto result = stx::All(a, a + count, [](int) { return true; });

	EXPECT_TRUE(result);
}

TEST(All, Basic)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);

	auto result = stx::All(a, a + count, [](int x) { return x < 999; });

	EXPECT_TRUE(result);
}

TEST(All, BasicFalse)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);

	auto result = stx::All(a, a + count, [](int x) { return x < -999; });

	EXPECT_FALSE(result);
}

TEST(All, Efficient)
{
	int a[] = { 1, 2, 3 };
	size_t count = sizeof(a) / sizeof(a[0]);
	size_t applicationCount = 0;

	auto result = stx::All(a, a + count, [&](int x) { ++applicationCount;  return x < 2; });

	EXPECT_FALSE(result);
	EXPECT_LT(applicationCount, count);
}

