#include <stx/algorithm/ForEach.h>
#include <gtest/gtest.h>
#include <vector>

TEST(ForEach, Empty)
{
	std::vector<int> v;
	int count = 0;
	stx::ForEach(v.begin(), v.end(), [&](int) { ++count; });

	EXPECT_EQ(0, count);
}

TEST(ForEach, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	size_t count = 0;
	stx::ForEach(v.begin(), v.end(), [&](int) { ++count; });

	EXPECT_EQ(v.size(), count);
}

struct ForEachAccumulator
{
	ForEachAccumulator()
		:
		Count(0)
	{ }

	void operator()(int /*value*/)
	{
		++Count;
	}

	size_t Count;
};

TEST(ForEach, Accumulator)
{
	std::vector<int> v = { 1, 2, 3 };
	
	auto accum = stx::ForEach(v.begin(), v.end(), ForEachAccumulator());

	EXPECT_EQ(v.size(), accum.Count);
}

TEST(For, Empty)
{
	std::vector<int> v;
	int count = 0;
	stx::For(v.begin(), v.end(), [&](int /*value*/, int /*index*/) { ++count; });

	EXPECT_EQ(0, count);
}

TEST(For, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	size_t count = 0;
	stx::For(v.begin(), v.end(), [&](int /*value*/, int /*index*/) { ++count; });

	EXPECT_EQ(v.size(), count);
}

TEST(For, Index)
{
	std::vector<int> v = { 0, 1, 2, 3 };
	size_t count = 0;
	stx::For(v.begin(), v.end(), [&](int x, int index) { if (x == index) ++count; });

	EXPECT_EQ(v.size(), count);
}

struct ForAccumulator
{
	ForAccumulator()
		:
		Count(0)
	{ }

	void operator()(int /*value*/, int /*index*/)
	{
		++Count;
	}

	size_t Count;
};

TEST(For, Accumulator)
{
	std::vector<int> v = { 1, 2, 3 };
	
	auto accum = stx::For(v.begin(), v.end(), ForAccumulator());

	EXPECT_EQ(v.size(), accum.Count);
}

