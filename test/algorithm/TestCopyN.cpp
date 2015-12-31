#include <stx/algorithm/CopyN.h>
#include <gtest/gtest.h>
#include <vector>
#include <iterator>

TEST(CopyN, Empty)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::CopyN(v.begin(), v.size(), output.begin());

	EXPECT_EQ(output.begin(), result);
}

TEST(CopyN, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(5, 0);
	auto result = stx::CopyN(v.begin(), v.size(), output.begin());

	EXPECT_EQ(output.begin() + v.size(), result);
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[1], output[1]);
	EXPECT_EQ(v[2], output[2]);
}

