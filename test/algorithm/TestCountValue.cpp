#include <stx/algorithm/CountValue.h>
#include <gtest/gtest.h>

TEST(CountValue, Empty)
{
	int a[] = {};

	auto result = stx::CountValue(a, a, 0);

	EXPECT_EQ(0, result);
}

TEST(CountValue, None)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);

	auto result = stx::CountValue(a, a + count, 0);

	EXPECT_EQ(0, result);
}

TEST(CountValue, One)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);

	auto result = stx::CountValue(a, a + count, 2);

	EXPECT_EQ(1, result);
}

TEST(CountValue, Some)
{
	int a[] = { 1, 2, 3, 2 };
	auto count = sizeof(a) / sizeof(a[0]);

	auto result = stx::CountValue(a, a + count, 2);

	EXPECT_EQ(2, result);
}

