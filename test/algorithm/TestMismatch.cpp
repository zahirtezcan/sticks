#include <stx/algorithm/Mismatch.h>
#include <gtest/gtest.h>

TEST(Mismatch, Empty)
{
	int a[] = { 1, 2 ,3 };
	int b[] = { 1, 2, 3 };
	auto result = stx::Mismatch(a, a, b, b);

	EXPECT_EQ(a, result.first);
	EXPECT_EQ(b, result.second);
}

TEST(Mismatch, EmptyPredicate)
{
	int a[] = { 1, 2 ,3 };
	int b[] = { 1, 2, 3 };
	auto result = stx::Mismatch(a, a, b, b, [](int, int) { return false; });

	EXPECT_EQ(a, result.first);
	EXPECT_EQ(b, result.second);
}

TEST(Mismatch, Basic)
{
	int a[] = { 1, 2, 3 };
	int b[] = { 1, 2, 3 };
	auto acount = sizeof(a) / sizeof(a[0]);
	auto bcount = sizeof(b) / sizeof(b[0]);
	auto aend = a + acount;
	auto bend = b + bcount;

	auto result = stx::Mismatch(a, aend, b, bend);

	EXPECT_EQ(aend, result.first);
	EXPECT_EQ(bend, result.second);
}

TEST(Mismatch, BasicMismatch)
{
	int a[] = { 1, 2, 3 };
	int b[] = { 1, 4, 3 };
	auto acount = sizeof(a) / sizeof(a[0]);
	auto bcount = sizeof(b) / sizeof(b[0]);
	auto aend = a + acount;
	auto bend = b + bcount;

	auto result = stx::Mismatch(a, aend, b, bend);

	EXPECT_EQ(a + 1, result.first);
	EXPECT_EQ(b + 1, result.second);
}

TEST(Mismatch, BasicPredicate)
{
	int a[] = { 1, 2, 3 };
	int b[] = { 1, 2, 3 };
	auto acount = sizeof(a) / sizeof(a[0]);
	auto bcount = sizeof(b) / sizeof(b[0]);
	auto aend = a + acount;
	auto bend = b + bcount;

	auto result = stx::Mismatch(a, a + acount, b, b + bcount, [](int x, int y) { return x == y; });

	EXPECT_EQ(aend, result.first);
	EXPECT_EQ(bend, result.second);
}

TEST(Mismatch, BasicMismatchPredicate)
{
	int a[] = { 1, 2, 3 };
	int b[] = { 1, 4, 3 };
	auto acount = sizeof(a) / sizeof(a[0]);
	auto bcount = sizeof(b) / sizeof(b[0]);
	auto aend = a + acount;
	auto bend = b + bcount;

	auto result = stx::Mismatch(a, aend, b, bend, [](int x, int y) { return x == y; });

	EXPECT_EQ(a + 1, result.first);
	EXPECT_EQ(b + 1, result.second);
}

TEST(Mismatch, MismatchPredicate)
{
	int a[] = { 1, 2, 3 };
	int b[] = { 11, 12, 31 };
	auto acount = sizeof(a) / sizeof(a[0]);
	auto bcount = sizeof(b) / sizeof(b[0]);
	auto aend = a + acount;
	auto bend = b + bcount;

	auto result = stx::Mismatch(a, aend, b, bend, [](int x, int y) { return x % 10 == y % 10; });

	EXPECT_EQ(a + 2, result.first);
	EXPECT_EQ(b + 2, result.second);
}

TEST(Mismatch, LengthMismatch)
{
	int a[] = { 1, 2, 3 };
	int b[] = { 1, 2 };
	auto acount = sizeof(a) / sizeof(a[0]);
	auto bcount = sizeof(b) / sizeof(b[0]);

	auto result = stx::Mismatch(a, a + acount, b, b + bcount);

	EXPECT_EQ(a + bcount, result.first);
	EXPECT_EQ(b + bcount, result.second);
}

