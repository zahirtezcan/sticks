#include <stx/algorithm/Any.h>
#include <gtest/gtest.h>

TEST(Any, Empty)
{
	int a[] = { 1, 2 ,3 };
	auto result = stx::Any(a, a, [](int) { return true; });

	EXPECT_FALSE(result);
}

TEST(Any, Dumb)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);

	auto result = stx::Any(a, a + count, [](int) { return true; });

	EXPECT_TRUE(result);
}

TEST(Any, Basic)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);

	auto result = stx::Any(a, a + count, [](int x) { return x < 999; });

	EXPECT_TRUE(result);
}

TEST(Any, BasicFalse)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);

	auto result = stx::Any(a, a + count, [](int x) { return x < -999; });

	EXPECT_FALSE(result);
}

TEST(Any, Efficient)
{
	int a[] = { 1, 2, 3 };
	size_t count = sizeof(a) / sizeof(a[0]);
	size_t applicationCount = 0;

	auto result = stx::Any(a, a + count, [&](int x) { ++applicationCount;  return x > 1; });

	EXPECT_TRUE(result);
	EXPECT_LT(applicationCount, count);
}

