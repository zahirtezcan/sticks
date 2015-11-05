#include <stx/algorithm/FindPartitionPoint.h>
#include <stx/algorithm/Rotate.h>
#include <gtest/gtest.h>

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

