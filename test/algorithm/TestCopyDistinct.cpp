#include <stx/algorithm/CopyDistinct.h>
#include <gtest/gtest.h>
#include <vector>
#include <iterator>

TEST(CopyDistinctConsecutively, Empty)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::CopyDistinctConsecutively(v.begin(), v.end(),
	                                             output.begin());

	EXPECT_EQ(output.begin(), result);
}

TEST(CopyDistinctConsecutively, BasicNoRepetition)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(5, 0);
	auto result = stx::CopyDistinctConsecutively(v.begin(), v.end(),
	                                             output.begin());

	EXPECT_EQ(output.begin() + v.size(), result);
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[1], output[1]);
	EXPECT_EQ(v[2], output[2]);
}

TEST(CopyDistinctConsecutively, BasicOutputIterator)
{
	std::vector<int> v = { 1, 1, 2, 1, 1, 1 };
	std::vector<int> output;
        stx::CopyDistinctConsecutively(v.begin(), v.end(),
	                               std::back_inserter(output));

	EXPECT_EQ(v.size() - 3, output.size());
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[2], output[1]);
	EXPECT_EQ(v[3], output[2]);
}

TEST(CopyDistinct, Empty)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::CopyDistinct(v.begin(), v.end(), output.begin());

	EXPECT_EQ(output.begin(), result);
}

TEST(CopyDistinct, BasicNoRepetition)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(5, 0);
	auto result = stx::CopyDistinct(v.begin(), v.end(), output.begin());

	EXPECT_EQ(output.begin() + v.size(), result);
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[1], output[1]);
	EXPECT_EQ(v[2], output[2]);
}

TEST(CopyDistinct, Basic)
{
	std::vector<int> v = { 1, 1, 2, 2, 1, 3, 3 };
	std::vector<int> output(v.size(), 0);
        auto result = stx::CopyDistinct(v.begin(), v.end(), output.begin());

	EXPECT_EQ(output.begin() + 3, result);
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[2], output[1]);
	EXPECT_EQ(v[5], output[2]);
}

