#include <stx/algorithm/Move.h>
#include <gtest/gtest.h>
#include <vector>
#include <iterator>

TEST(Move, Empty)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::Move(v.begin(), v.end(), output.begin());

	EXPECT_EQ(output.begin(), result);
}

TEST(Move, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(5, 0);
	auto result = stx::Move(v.begin(), v.end(), output.begin());

	EXPECT_EQ(output.begin() + v.size(), result);
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[1], output[1]);
	EXPECT_EQ(v[2], output[2]);
}

TEST(Move, BasicOutputIterator)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output;
        stx::Move(v.begin(), v.end(), std::back_inserter(output));

	EXPECT_EQ(v.size(), output.size());
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[1], output[1]);
	EXPECT_EQ(v[2], output[2]);
}

TEST(MoveN, Empty)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::MoveN(v.begin(), v.size(), output.begin());

	EXPECT_EQ(output.begin(), result);
}

TEST(MoveN, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(5, 0);
	auto result = stx::MoveN(v.begin(), v.size(), output.begin());

	EXPECT_EQ(output.begin() + v.size(), result);
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[1], output[1]);
	EXPECT_EQ(v[2], output[2]);
}

TEST(MoveBackward, Empty)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::MoveBackward(v.begin(), v.end(), output.end());

	EXPECT_EQ(output.end(), result);
}

TEST(MoveBackward, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(5, 0);
	auto result = stx::MoveBackward(v.begin(), v.end(), output.end());

	EXPECT_EQ(output.end() - v.size(), result);
	EXPECT_EQ(v[0], output[2]);
	EXPECT_EQ(v[1], output[3]);
	EXPECT_EQ(v[2], output[4]);
}

TEST(MoveIf, Empty)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::MoveIf(v.begin(), v.end(), output.begin(),
	                          [](int){ return true; });

	EXPECT_EQ(output.begin(), result);
}

TEST(MoveIf, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(5, 0);
	auto result = stx::MoveIf(v.begin(), v.end(), output.begin(),
	                          [](int x){ return x % 2 != 0; });

	EXPECT_EQ(output.begin() + 2, result);
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[2], output[1]);
}

TEST(MoveIf, BasicOutputIterator)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output;
        stx::MoveIf(v.begin(), v.end(), std::back_inserter(output),
	                          [](int x){ return x % 2 != 0; });

	EXPECT_EQ(std::vector<int>::size_type(2), output.size());
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[2], output[1]);
}

TEST(MoveReversed, Empty)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::MoveReversed(v.begin(), v.end(), output.begin());

	EXPECT_EQ(output.begin(), result);
}

TEST(MoveReversed, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(5, 0);
	auto result = stx::MoveReversed(v.begin(), v.end(), output.begin());

	EXPECT_EQ(output.begin() + v.size(), result);
	EXPECT_EQ(v[2], output[0]);
	EXPECT_EQ(v[1], output[1]);
	EXPECT_EQ(v[0], output[2]);
}

TEST(MoveReversed, BasicOutputIterator)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output;
        stx::MoveReversed(v.begin(), v.end(), std::back_inserter(output));

	EXPECT_EQ(v.size(), output.size());
	EXPECT_EQ(v[2], output[0]);
	EXPECT_EQ(v[1], output[1]);
	EXPECT_EQ(v[0], output[2]);
}

TEST(MoveReplaced, Empty)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::MoveReplaced(v.begin(), v.end(), output.begin(),
	                                [](int) { return true; }, -1);

	EXPECT_EQ(output.begin(), result);
}

TEST(MoveReplaced, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(5, 0);
	auto result = stx::MoveReplaced(v.begin(), v.end(), output.begin(),
	                                [](int) { return true; }, -1);

	EXPECT_EQ(output.begin() + v.size(), result);
	EXPECT_EQ(-1, output[0]);
	EXPECT_EQ(-1, output[1]);
	EXPECT_EQ(-1, output[2]);
}

TEST(MoveReplaced, BasicOutputIterator)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output;
        stx::MoveReplaced(v.begin(), v.end(), std::back_inserter(output),
	                  [](int x) { return x % 2 == 0; }, -1 );

	EXPECT_EQ(v.size(), output.size());
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(-1, output[1]);
	EXPECT_EQ(v[2], output[2]);
}

TEST(MoveRemoved, Empty)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::MoveRemoved(v.begin(), v.end(), output.begin(),
	                               [](int) { return true; });

	EXPECT_EQ(output.begin(), result);
}

TEST(MoveRemoved, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(5, 0);
	auto result = stx::MoveRemoved(v.begin(), v.end(), output.begin(),
	                               [](int x) { return x % 2 == 1; });

	EXPECT_EQ(output.begin() + 1, result);
	EXPECT_EQ(v[1], output[0]);
}

TEST(MoveRemoved, BasicOutputIterator)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output;
        stx::MoveRemoved(v.begin(), v.end(), std::back_inserter(output),
	                  [](int x) { return x % 2 == 0; });

	EXPECT_EQ(v.size() - 1, output.size());
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[2], output[1]);
}

TEST(MoveRotated, EmptyBegin)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::MoveRotated(v.begin(), v.begin(), v.end(),
	                               output.begin());

	EXPECT_EQ(output.begin(), result);
}

TEST(MoveRotated, EmptyEnd)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::MoveRotated(v.begin(), v.end(), v.end(),
	                               output.begin());

	EXPECT_EQ(output.begin(), result);
}

TEST(MoveRotated, Basic)
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	std::vector<int> output(5, 0);
	auto result = stx::MoveRotated(v.begin(), v.begin() + 3, v.end(),
	                               output.begin());

	EXPECT_EQ(output.begin() + v.size(), result);
	EXPECT_EQ(v[3], output[0]);
	EXPECT_EQ(v[4], output[1]);
	EXPECT_EQ(v[0], output[2]);
	EXPECT_EQ(v[1], output[3]);
	EXPECT_EQ(v[2], output[4]);
}

TEST(MoveRotated, BasicOutputIterator)
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	std::vector<int> output;
        stx::MoveRotated(v.begin(), v.begin() + 3, v.end(),
	                 std::back_inserter(output));

	EXPECT_EQ(v.size(), output.size());
	EXPECT_EQ(v[3], output[0]);
	EXPECT_EQ(v[4], output[1]);
	EXPECT_EQ(v[0], output[2]);
	EXPECT_EQ(v[1], output[3]);
	EXPECT_EQ(v[2], output[4]);
}
/*
TEST(MoveDistinctConsecutively, Empty)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::MoveDistinctConsecutively(v.begin(), v.end(),
	                                             output.begin());

	EXPECT_EQ(output.begin(), result);
}

TEST(MoveDistinctConsecutively, BasicNoRepetition)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(5, 0);
	auto result = stx::MoveDistinctConsecutively(v.begin(), v.end(),
	                                             output.begin());

	EXPECT_EQ(output.begin() + v.size(), result);
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[1], output[1]);
	EXPECT_EQ(v[2], output[2]);
}

TEST(MoveDistinctConsecutively, BasicOutputIterator)
{
	std::vector<int> v = { 1, 1, 2, 1, 1, 1 };
	std::vector<int> output;
        stx::MoveDistinctConsecutively(v.begin(), v.end(),
	                               std::back_inserter(output));

	EXPECT_EQ(v.size() - 3, output.size());
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[2], output[1]);
	EXPECT_EQ(v[3], output[2]);
}

TEST(MoveDistinct, Empty)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::MoveDistinct(v.begin(), v.end(), output.begin());

	EXPECT_EQ(output.begin(), result);
}

TEST(MoveDistinct, BasicNoRepetition)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(5, 0);
	auto result = stx::MoveDistinct(v.begin(), v.end(), output.begin());

	EXPECT_EQ(output.begin() + v.size(), result);
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[1], output[1]);
	EXPECT_EQ(v[2], output[2]);
}

TEST(MoveDistinct, Basic)
{
	std::vector<int> v = { 1, 1, 2, 2, 1, 3, 3 };
	std::vector<int> output(v.size(), 0);
        auto result = stx::MoveDistinct(v.begin(), v.end(), output.begin());

	EXPECT_EQ(output.begin() + 3, result);
	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[2], output[1]);
	EXPECT_EQ(v[5], output[2]);
}
*/
