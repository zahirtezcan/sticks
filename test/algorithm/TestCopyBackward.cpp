#include <stx/algorithm/CopyBackward.h>
#include <gtest/gtest.h>
#include <vector>
#include <iterator>

TEST(CopyBackward, Empty)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::CopyBackward(v.begin(), v.end(), output.end());

	EXPECT_EQ(output.end(), result);
}

TEST(CopyBackward, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(5, 0);
	auto result = stx::CopyBackward(v.begin(), v.end(), output.end());

	EXPECT_EQ(output.end() - v.size(), result);
	EXPECT_EQ(v[0], output[2]);
	EXPECT_EQ(v[1], output[3]);
	EXPECT_EQ(v[2], output[4]);
}

