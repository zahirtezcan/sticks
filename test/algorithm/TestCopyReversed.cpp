#include <stx/algorithm/CopyReversed.h>
#include <gtest/gtest.h>
#include <vector>
#include <iterator>

TEST(CopyReversed, Empty)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::CopyReversed(v.begin(), v.end(), output.begin());

	EXPECT_EQ(output.begin(), result);
}

TEST(CopyReversed, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(5, 0);
	auto result = stx::CopyReversed(v.begin(), v.end(), output.begin());

	EXPECT_EQ(output.begin() + v.size(), result);
	EXPECT_EQ(v[2], output[0]);
	EXPECT_EQ(v[1], output[1]);
	EXPECT_EQ(v[0], output[2]);
}

TEST(CopyReversed, BasicOutputIterator)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output;
        stx::CopyReversed(v.begin(), v.end(), std::back_inserter(output));

	EXPECT_EQ(v.size(), output.size());
	EXPECT_EQ(v[2], output[0]);
	EXPECT_EQ(v[1], output[1]);
	EXPECT_EQ(v[0], output[2]);
}

