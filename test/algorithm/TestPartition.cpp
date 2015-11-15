#include <stx/algorithm/Partition.h>
#include <stx/algorithm/Rotate.h>
#include <gtest/gtest.h>

TEST(IsPartitioned, Empty)
{
	int a[] = {};
	auto end = a;
	bool result = stx::IsPartitioned(a, end, [](int) { return false; });

	EXPECT_TRUE(result);
}

TEST(IsPartitioned, All)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);
	auto end = a + count;

	bool result = stx::IsPartitioned(a, end, [](int x) { return x < 999; });

	EXPECT_TRUE(result);
}

TEST(IsPartitioned, None)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);
	auto end = a + count;

	bool result = stx::IsPartitioned(a, end, [](int x) { return x > 999; });

	EXPECT_TRUE(result);
}

TEST(IsPartitioned, Basic)
{
	int a[] = { 1, 2, 3, -1, -2, -3 };
	auto count = sizeof(a) / sizeof(a[0]);
	auto end = a + count;

	bool result = stx::IsPartitioned(a, end, [](int x) { return x > 0; });

	EXPECT_TRUE(result);
}

TEST(IsPartitioned, False)
{
	int a[] = { 1, 2, 3, -1, 2, -3 };
	auto count = sizeof(a) / sizeof(a[0]);
	auto end = a + count;

	bool result = stx::IsPartitioned(a, end, [](int x) { return x > 0; });

	EXPECT_FALSE(result);
}

TEST(Partition, Empty)
{
	int a[] = {};
	auto end = a;

	auto ppoint = stx::Partition(a, end, [](int) { return true; });
	
	EXPECT_EQ(end, ppoint);
}

TEST(Partition, All)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);
	auto end = a + count;

	auto result = stx::Partition(a, end, [](int x) { return x < 999; });

	EXPECT_EQ(end, result);
	EXPECT_EQ(1, a[0]);
	EXPECT_EQ(2, a[1]);
	EXPECT_EQ(3, a[2]);
}

TEST(Partition, None)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);
	auto end = a + count;

	auto result = stx::Partition(a, end, [](int x) { return x > 999; });

	EXPECT_EQ(a, result);
	EXPECT_EQ(1, a[0]);
	EXPECT_EQ(2, a[1]);
	EXPECT_EQ(3, a[2]);
}

TEST(Partition, Basic)
{
	int a[] = { -1, 1, -2, 2, -3, 3 };
	auto count = sizeof(a) / sizeof(a[0]);
	auto end = a + count;

	auto result = stx::Partition(a, end, [](int x) { return x > 0; });

	EXPECT_EQ(a + 3, result);
	EXPECT_GT(a[0], 0);
	EXPECT_GT(a[1], 0);
	EXPECT_GT(a[2], 0);
	EXPECT_LT(a[3], 0);
	EXPECT_LT(a[4], 0);
	EXPECT_LT(a[5], 0);
}

TEST(FindPartitionPoint, Empty)
{
	int a[] = {};
	auto end = a;
	auto found = stx::FindPartitionPoint(a, end, [](int x) { return x == 0; });

	EXPECT_EQ(end, found);
}

TEST(FindPartitionPoint, All)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);
	auto end = a + count;

	auto found = stx::FindPartitionPoint(a, end, [](int x) { return x < 999; });

	EXPECT_EQ(end, found);
}

TEST(FindPartitionPoint, None)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);
	auto begin = a;
	auto end = a + count;

	auto found = stx::FindPartitionPoint(begin, end, [](int x) { return x > 999; });

	EXPECT_EQ(begin, found);
}

TEST(FindPartitionPoint, Mid)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);
	auto begin = a;
	auto end = a + count;

	auto found = stx::FindPartitionPoint(begin, end, [=](int x) { return x < a[count / 2]; });

	EXPECT_EQ(begin + count / 2, found);

}

TEST(FindPartitionPoint, Regress)
{
	for (size_t i = 0; i < 100; ++i) {
		int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		auto count = sizeof(a) / sizeof(a[0]);
		if (i > count) break;

		stx::Rotate(a, a + i, a + count);
		auto expected = a + count - (i == count ? 0 : i);

		auto result = stx::FindPartitionPoint(a, a + count,[=](int x) { return x >= a[0]; });

		EXPECT_EQ(expected, result);
	}
}

