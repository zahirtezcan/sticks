#include <stx/algorithm/Find.h>
#include <gtest/gtest.h>
#include <vector>

TEST(Find, Empty)
{
	std::vector<int> v;

	auto result = stx::Find(v.begin(), v.end(), [](int x) { return x == 3; });

	EXPECT_EQ(v.end(), result);
}

TEST(Find, Basic)
{
	std::vector<int> v = { 1, 2 ,3 };

	auto result = stx::Find(v.begin(), v.end(), [](int x) { return x == 2; });

	EXPECT_EQ(v.begin() + 1, result);
}

TEST(FindValue, Empty)
{
	std::vector<int> v;

	auto result = stx::FindValue(v.begin(), v.end(), 0);

	EXPECT_EQ(v.end(), result);
}

TEST(FindValue, Basic)
{
	std::vector<int> v = { 1, 2 ,3 };

	auto result = stx::FindValue(v.begin(), v.end(), 2);

	EXPECT_EQ(v.begin() + 1, result);
}

TEST(FindAny, Empty)
{
	std::vector<int> v;
	std::vector<int> t = { 2, 3, 4 };

	auto result = stx::FindAny(v.begin(), v.end(), t.begin(), t.end());

	EXPECT_EQ(v.end(), result);
}

TEST(FindAny, NoValue)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> t;

	auto result = stx::FindAny(v.begin(), v.end(), t.begin(), t.end());

	EXPECT_EQ(v.end(), result);
}

TEST(FindAny, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> t = { 2, 3, 4 };

	auto result = stx::FindAny(v.begin(), v.end(), t.begin(), t.end());

	EXPECT_EQ(v.begin() + 1, result);
}

TEST(FindAnyPredicate, Empty)
{
	std::vector<int> v;
	std::vector<int> t = { 2, 3, 4 };

	auto result = stx::FindAny(v.begin(), v.end(), t.begin(), t.end(), [] (int, int) { return true; });

	EXPECT_EQ(v.end(), result);
}

TEST(FindAnyPredicate, NoValue)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> t;

	auto result = stx::FindAny(v.begin(), v.end(), t.begin(), t.end(), [] (int, int) { return true; });

	EXPECT_EQ(v.end(), result);
}

TEST(FindAnyPredicate, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> t = { 2, 3, 4 };

	auto result = stx::FindAny(v.begin(), v.end(), t.begin(), t.end(), [] (int x, int y) { return x == y; });

	EXPECT_EQ(v.begin() + 1, result);
}

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

TEST(FindLastSequence, Empty)
{
	std::vector<int> v;
	std::vector<int> t = { 2, 3, 4 };

	auto result = stx::FindLastSequence(v.begin(), v.end(), t.begin(), t.end());

	EXPECT_EQ(v.end(), result);
}

TEST(FindLastSequence, NoValue)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> t;

	auto result = stx::FindLastSequence(v.begin(), v.end(), t.begin(), t.end());

	EXPECT_EQ(v.end(), result);
}

TEST(FindLastSequence, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> t = { 2, 3 };

	auto result = stx::FindLastSequence(v.begin(), v.end(), t.begin(), t.end());

	EXPECT_EQ(v.begin() + 1, result);
}

TEST(FindLastSequence, Duplicate)
{
	std::vector<int> v = { 1, 2, 3, 2, 3 };
	std::vector<int> t = { 2, 3 };

	auto result = stx::FindLastSequence(v.begin(), v.end(), t.begin(), t.end());

	EXPECT_EQ(v.begin() + 3, result);
}

