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

TEST(CopyPartitioned, Empty)
{
	std::vector<int> v;
	std::vector<int> output;
        stx::CopyPartitioned(v.begin(), v.end(),
	                     std::back_inserter(output),
	                     std::back_inserter(output),
	                     [](int x){ return x % 2 != 0; });

	EXPECT_TRUE(output.empty());
}

TEST(CopyPartitioned, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output = { 0, 0, 0 };
        stx::CopyPartitioned(v.begin(), v.end(),
	                     output.begin(),
	                     output.begin() + 2,
	                     [](int x){ return x % 2 != 0; });

	EXPECT_EQ(1, output[0]);
	EXPECT_EQ(3, output[1]);
	EXPECT_EQ(2, output[2]);
}

TEST(CopyPartitioned, BasicOutputIterator)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> trueOutput;
	std::vector<int> falseOutput;
        stx::CopyPartitioned(v.begin(), v.end(),
	                     std::back_inserter(trueOutput),
	                     std::back_inserter(falseOutput),
	                     [](int x){ return x % 2 != 0; });
	
	EXPECT_EQ(std::vector<int>::size_type(2), trueOutput.size());
	EXPECT_EQ(std::vector<int>::size_type(1), falseOutput.size());
	EXPECT_EQ(1, trueOutput[0]);
	EXPECT_EQ(3, trueOutput[1]);
	EXPECT_EQ(2, falseOutput[0]);
}

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

TEST(CopyReplaced, Empty)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::CopyReplaced(v.begin(), v.end(), output.begin(),
	                                [](int) { return true; }, -1);

	EXPECT_EQ(output.begin(), result);
}

TEST(CopyReplaced, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(5, 0);
	auto result = stx::CopyReplaced(v.begin(), v.end(), output.begin(),
	                                [](int) { return true; }, -1);

	EXPECT_EQ(output.begin() + v.size(), result);
	EXPECT_EQ(-1, output[0]);
	EXPECT_EQ(-1, output[1]);
	EXPECT_EQ(-1, output[2]);
}

TEST(CopyReplaced, BasicOutputIterator)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output;
        stx::CopyReplaced(v.begin(), v.end(), std::back_inserter(output),
	                  [](int x) { return x % 2 == 0; }, -1 );

	EXPECT_EQ(v.size(), output.size());
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(-1, output[1]);
	EXPECT_EQ(v[2], output[2]);
}

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


