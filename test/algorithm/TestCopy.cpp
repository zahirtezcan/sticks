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

TEST(CopyRemoved, Empty)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::CopyRemoved(v.begin(), v.end(), output.begin(),
	                               [](int) { return true; });

	EXPECT_EQ(output.begin(), result);
}

TEST(CopyRemoved, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(5, 0);
	auto result = stx::CopyRemoved(v.begin(), v.end(), output.begin(),
	                               [](int x) { return x % 2 == 1; });

	EXPECT_EQ(output.begin() + 1, result);
	EXPECT_EQ(v[1], output[0]);
}

TEST(CopyRemoved, BasicOutputIterator)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output;
        stx::CopyRemoved(v.begin(), v.end(), std::back_inserter(output),
	                  [](int x) { return x % 2 == 0; });

	EXPECT_EQ(v.size() - 1, output.size());
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[2], output[1]);
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

