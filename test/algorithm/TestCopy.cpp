#include <stx/algorithm/Copy.h>
#include <gtest/gtest.h>
#include <vector>
#include <iterator>

TEST(Copy, Empty)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::Copy(v.begin(), v.end(), output.begin());

	EXPECT_EQ(output.begin(), result);
}

TEST(Copy, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(5, 0);
	auto result = stx::Copy(v.begin(), v.end(), output.begin());

	EXPECT_EQ(output.begin() + v.size(), result);
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[1], output[1]);
	EXPECT_EQ(v[2], output[2]);
}

TEST(Copy, BasicOutputIterator)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output;
        stx::Copy(v.begin(), v.end(), std::back_inserter(output));

	EXPECT_EQ(v.size(), output.size());
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[1], output[1]);
	EXPECT_EQ(v[2], output[2]);
}

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

TEST(CopyIf, Empty)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::CopyIf(v.begin(), v.end(), output.begin(),
	                          [](int){ return true; });

	EXPECT_EQ(output.begin(), result);
}

TEST(CopyIf, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(5, 0);
	auto result = stx::CopyIf(v.begin(), v.end(), output.begin(),
	                          [](int x){ return x % 2 != 0; });

	EXPECT_EQ(output.begin() + 2, result);
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[2], output[1]);
}

TEST(CopyIf, BasicOutputIterator)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output;
        stx::CopyIf(v.begin(), v.end(), std::back_inserter(output),
	                          [](int x){ return x % 2 != 0; });

	EXPECT_EQ(std::vector<int>::size_type(2), output.size());
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[2], output[1]);
}

