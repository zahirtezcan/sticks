#include <stx/algorithm/AllEqual.h>
#include <gtest/gtest.h>

TEST(AllEqual, Empty)
{
	int a[] = { 1, 2 ,3 };
	int b[] = { 1, 2, 3 };
	auto result = stx::AllEqual(a, a, b, b);

	EXPECT_TRUE(result);
}

TEST(AllEqual, EmptyPredicate)
{
	int a[] = { 1, 2 ,3 };
	int b[] = { 1, 2, 3 };
	auto result = stx::AllEqual(a, a, b, b, [](int, int) { return false; });

	EXPECT_TRUE(result);
}

TEST(AllEqual, Basic)
{
	int a[] = { 1, 2, 3 };
	int b[] = { 1, 2, 3 };
	auto acount = sizeof(a) / sizeof(a[0]);
	auto bcount = sizeof(b) / sizeof(b[0]);

	auto result = stx::AllEqual(a, a + acount, b, b + bcount);

	EXPECT_TRUE(result);
}

TEST(AllEqual, BasicPredicate)
{
	int a[] = { 1, 2, 3 };
	int b[] = { 1, 2, 3 };
	auto acount = sizeof(a) / sizeof(a[0]);
	auto bcount = sizeof(b) / sizeof(b[0]);

	auto result = stx::AllEqual(a, a + acount, b, b + bcount, [](int x, int y) { return x == y; });

	EXPECT_TRUE(result);
}

TEST(AllEqual, BasicEquivalence)
{
	int a[] = { 1, 2, 3 };
	int b[] = { 11, 12, 13 };
	auto acount = sizeof(a) / sizeof(a[0]);
	auto bcount = sizeof(b) / sizeof(b[0]);

	auto result = stx::AllEqual(a, a + acount, b, b + bcount, [](int x, int y) { return x % 10 == y % 10; });

	EXPECT_TRUE(result);
}

TEST(AllEqual, BasicFalse)
{
	int a[] = { 1, 2, 3 };
	int b[] = { 1, 2, 4 };
	auto acount = sizeof(a) / sizeof(a[0]);
	auto bcount = sizeof(b) / sizeof(b[0]);

	auto result = stx::AllEqual(a, a + acount, b, b + bcount);

	EXPECT_FALSE(result);
}

TEST(AllEqual, BasicFalsePredicate)
{
	int a[] = { 1, 2, 3 };
	int b[] = { 1, 2, 4 };
	auto acount = sizeof(a) / sizeof(a[0]);
	auto bcount = sizeof(b) / sizeof(b[0]);

	auto result = stx::AllEqual(a, a + acount, b, b + bcount, [](int x, int y) { return x == y; } );

	EXPECT_FALSE(result);
}

TEST(AllEqual, NoneEquals)
{
	int a[] = { 1, 2, 3 };
	int b[] = { 4, 5, 6 };
	auto acount = sizeof(a) / sizeof(a[0]);
	auto bcount = sizeof(b) / sizeof(b[0]);

	auto result = stx::AllEqual(a, a + acount, b, b + bcount, [](int x, int y) { return x != y; } );

	EXPECT_TRUE(result);
}

TEST(AllEqual, LengthMismatch)
{
	int a[] = { 1, 2, 3 };
	int b[] = { 1, 2 };
	auto acount = sizeof(a) / sizeof(a[0]);
	auto bcount = sizeof(b) / sizeof(b[0]);

	auto result = stx::AllEqual(a, a + acount, b, b + bcount);

	EXPECT_FALSE(result);
}

/*TODO: Test early exit for random access iter length mismatch */

TEST(AllEqual, EarlyExit)
{
	int a[] = { 1, 2, 3 };
	int b[] = { 1, 5, 3 };
	auto acount = sizeof(a) / sizeof(a[0]);
	auto bcount = sizeof(b) / sizeof(b[0]);
	size_t applicationCount = 0;

	auto result = stx::AllEqual(a, a + acount, b, b + bcount,
	                            [&](int x, int y) { ++applicationCount; return x == y; });

	EXPECT_FALSE(result);
	EXPECT_LT(applicationCount, acount);
}

