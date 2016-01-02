#include <stx/algorithm/Count.h>
#include <gtest/gtest.h>

TEST(Count, Empty)
{
	int a[] = {};

	auto result = stx::Count(a, a, [](int x) { return x == 0; });

	EXPECT_EQ(0, result);
}

TEST(Count, None)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);

	auto result = stx::Count(a, a + count, [](int x) { return x == 0; });

	EXPECT_EQ(0, result);
}

TEST(Count, One)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);

	auto result = stx::Count(a, a + count, [](int x) { return x == 2; });

	EXPECT_EQ(1, result);
}

TEST(Count, Some)
{
	int a[] = { 1, 2, 3, 2 };
	auto count = sizeof(a) / sizeof(a[0]);

	auto result = stx::Count(a, a + count, [](int x) { return x == 2; });

	EXPECT_EQ(2, result);
}

