#include <stx/algorithm/Reverse.h>
#include <gtest/gtest.h>

testing::AssertionResult AreEqual(int* a, int* b, int count)
{
	for (int i = 0; i < count; ++i) {
		if (a[i] != b[i]) {
			return testing::AssertionFailure() << " mismatch at index " << i;
		}
	}

	return testing::AssertionSuccess();
}

TEST(Reverse, Basic)
{
	int a[] = { 1, 2, 3 };
	int b[] = { 3, 2, 1 };
	int count = sizeof(a) / sizeof(a[0]);

	stx::Reverse(a, a + count);

	EXPECT_TRUE(AreEqual(a, b, count));
}

TEST(Reverse, DoubleReverse)
{
	int a[] = { 1, 2, 3 };
	int b[] = { 1, 2, 3 };
	int count = sizeof(a) / sizeof(a[0]);

	stx::Reverse(a, a + count);
	stx::Reverse(a, a + count);

	EXPECT_TRUE(AreEqual(a , b, count));
}

