#include <stx/algorithm/FindSequence.h>
#include <gtest/gtest.h>
#include <vector>

TEST(FindSequence, Empty)
{
	std::vector<int> v;
	std::vector<int> t = { 2, 3, 4 };

	auto result = stx::FindSequence(v.begin(), v.end(), t.begin(), t.end());

	EXPECT_EQ(v.end(), result);
}

TEST(FindSequence, NoValue)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> t;

	auto result = stx::FindSequence(v.begin(), v.end(), t.begin(), t.end());

	EXPECT_EQ(v.begin(), result);
}

TEST(FindSequence, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> t = { 2, 3 };

	auto result = stx::FindSequence(v.begin(), v.end(), t.begin(), t.end());

	EXPECT_EQ(v.begin() + 1, result);
}

TEST(FindSequencePredicate, Empty)
{
	std::vector<int> v;
	std::vector<int> t = { 2, 3, 4 };

	auto result = stx::FindSequence(v.begin(), v.end(), t.begin(), t.end(), [] (int, int) { return true; });

	EXPECT_EQ(v.end(), result);
}

TEST(FindSequencePredicate, NoValue)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> t;

	auto result = stx::FindSequence(v.begin(), v.end(), t.begin(), t.end(), [] (int, int) { return true; });

	EXPECT_EQ(v.begin(), result);
}

TEST(FindSequencePredicate, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> t = { 2, 3 };

	auto result = stx::FindSequence(v.begin(), v.end(), t.begin(), t.end(), [] (int x, int y) { return x == y; });

	EXPECT_EQ(v.begin() + 1, result);
}

TEST(FindSequencePredicate, RepeatedInitial)
{
	std::vector<int> v = { 1, 2, 2, 3 };
	std::vector<int> t = { 2, 3 };

	auto result = stx::FindSequence(v.begin(), v.end(), t.begin(), t.end(), [] (int x, int y) { return x == y; });

	EXPECT_EQ(v.begin() + 2, result);
}

TEST(FindSequencePredicate, RepeatedSequence)
{
	std::vector<int> v = { 1, 2, 3, 2, 3 };
	std::vector<int> t = { 2, 3 };

	auto result = stx::FindSequence(v.begin(), v.end(), t.begin(), t.end(), [] (int x, int y) { return x == y; });

	EXPECT_EQ(v.begin() + 1, result);
}

TEST(FindSequencePredicate, IncompleteSequence)
{
	std::vector<int> v = { 1, 2, 3, 4, 5, 6 };
	std::vector<int> t = { 4, 5, 6, 7 };

	auto result = stx::FindSequence(v.begin(), v.end(), t.begin(), t.end(), [] (int x, int y) { return x == y; });

	EXPECT_EQ(v.end(), result);
}

TEST(FindSequencePredicate, NonSequence)
{
	std::vector<int> v = { 1, 2, 3, 4, 5, 6 };
	std::vector<int> t = { 1, 3, 5, 7 };

	auto result = stx::FindSequence(v.begin(), v.end(), t.begin(), t.end(), [] (int x, int y) { return x != y; });

	EXPECT_EQ(v.end(), result);
}

