#include <stx/algorithm/Rotate.h>
#include <gtest/gtest.h>

template<typename Range>
testing::AssertionResult RangeEquals(Range& r1, Range&& r2)
{
	using std::begin;
	using std::end;

	auto b1 = begin(r1);
	auto e1 = end(r1);
	auto b2 = begin(r2);
	auto e2 = end(r2);

	while (b1 != e1 && b2 != e2) {
		if (*b1 != *b2) {
			return testing::AssertionFailure() << " mismatch at index: " << (b1 - begin(r1));
		}
		++b1;
		++b2;
	}

	if (b1 == e1 && b2 == e2) {
		return testing::AssertionSuccess();
	} else {
		return testing::AssertionFailure() << " range size mismatch";
	}
}

TEST(Rotate, Empty)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);
	
	stx::Rotate(a, a, a + count);

	EXPECT_TRUE(RangeEquals(a, { 1, 2, 3 }));
}

TEST(Rotate, ReverseEmpty)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);

	stx::Rotate(a, a + count, a + count);
	
	EXPECT_TRUE(RangeEquals(a, { 1, 2, 3 }));
}

TEST(Rotate, Basic)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);

	stx::Rotate(a, a + 1, a + count);
	
	EXPECT_TRUE(RangeEquals(a, { 2, 3, 1 }));
}

TEST(Rotate, NTimes)
{
	int a[] = { 1, 2, 3 };
	auto count = sizeof(a) / sizeof(a[0]);
	
	for (auto i = count; i > 0; --i) {
		stx::Rotate(a, a + 1, a + count);
	}
	
	EXPECT_TRUE(RangeEquals(a, { 1, 2, 3 }));
}

