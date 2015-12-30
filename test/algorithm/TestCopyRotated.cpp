#include <stx/algorithm/CopyRotated.h>
#include <gtest/gtest.h>
#include <vector>
#include <iterator>

TEST(CopyRotated, EmptyBegin)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::CopyRotated(v.begin(), v.begin(), v.end(),
	                               output.begin());

	EXPECT_EQ(output.begin(), result);
}

TEST(CopyRotated, EmptyEnd)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::CopyRotated(v.begin(), v.end(), v.end(),
	                               output.begin());

	EXPECT_EQ(output.begin(), result);
}

TEST(CopyRotated, Basic)
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	std::vector<int> output(5, 0);
	auto result = stx::CopyRotated(v.begin(), v.begin() + 3, v.end(),
	                               output.begin());

	EXPECT_EQ(output.begin() + v.size(), result);
	EXPECT_EQ(v[3], output[0]);
	EXPECT_EQ(v[4], output[1]);
	EXPECT_EQ(v[0], output[2]);
	EXPECT_EQ(v[1], output[3]);
	EXPECT_EQ(v[2], output[4]);
}

TEST(CopyRotated, BasicOutputIterator)
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	std::vector<int> output;
        stx::CopyRotated(v.begin(), v.begin() + 3, v.end(),
	                 std::back_inserter(output));

	EXPECT_EQ(v.size(), output.size());
	EXPECT_EQ(v[3], output[0]);
	EXPECT_EQ(v[4], output[1]);
	EXPECT_EQ(v[0], output[2]);
	EXPECT_EQ(v[1], output[3]);
	EXPECT_EQ(v[2], output[4]);
}

