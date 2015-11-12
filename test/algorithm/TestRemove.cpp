#include <stx/algorithm/Remove.h>
#include <gtest/gtest.h>
#include <vector>

TEST(Remove, Empty)
{
	std::vector<int> v;
	auto result = stx::Remove(v.begin(), v.end(), [](int x) { return x <= 0; });

	EXPECT_EQ(v.end(), result);
}

TEST(Remove, NoRemove)
{
	std::vector<int> v = { 1, 2, 3 };
	auto result = stx::Remove(v.begin(), v.end(), [](int x) { return x <= 0; });

	EXPECT_EQ(v.end(), result);
}

TEST(Remove, SingleRemove)
{
	std::vector<int> v = { 0, 1, 2, 3 };
	auto result = stx::Remove(v.begin(), v.end(), [](int x) { return x <= 0; });

	EXPECT_EQ(v.begin() + 3, result);
	EXPECT_EQ(1, v[0]);	
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(3, v[2]);
}

TEST(Remove, MultipleRemove)
{
	std::vector<int> v = { 0, -1, 1, -2, -3, 2, 3 };
	auto result = stx::Remove(v.begin(), v.end(), [](int x) { return x <= 0; });

	EXPECT_EQ(v.begin() + 3, result);
	EXPECT_EQ(1, v[0]);	
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(3, v[2]);
}

TEST(Remove, RemoveAll)
{
	std::vector<int> v = { 0, -1, -2, -3 };
	auto result = stx::Remove(v.begin(), v.end(), [](int x) { return x <= 0; });

	EXPECT_EQ(v.begin(), result);
}

TEST(RemoveValue, Empty)
{
	std::vector<int> v;
	auto result = stx::RemoveValue(v.begin(), v.end(), -1);

	EXPECT_EQ(v.end(), result);
}

TEST(RemoveValue, NoRemoveValue)
{
	std::vector<int> v = { 1, 2, 3 };
	auto result = stx::RemoveValue(v.begin(), v.end(), -1);

	EXPECT_EQ(v.end(), result);
}

TEST(RemoveValue, SingleRemoveValue)
{
	std::vector<int> v = { -1, 1, 2, 3 };
	auto result = stx::RemoveValue(v.begin(), v.end(), -1);

	EXPECT_EQ(v.begin() + 3, result);
	EXPECT_EQ(1, v[0]);	
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(3, v[2]);
}

TEST(RemoveValue, MultipleRemoveValue)
{
	std::vector<int> v = { -1, -1, 1, -1, -1, 2, 3 };
	auto result = stx::RemoveValue(v.begin(), v.end(), -1);

	EXPECT_EQ(v.begin() + 3, result);
	EXPECT_EQ(1, v[0]);	
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(3, v[2]);
}

TEST(RemoveValue, RemoveAll)
{
	std::vector<int> v = { -1, -1, -1, -1};
	auto result = stx::RemoveValue(v.begin(), v.end(), -1);

	EXPECT_EQ(v.begin(), result);
}

TEST(RemoveDuplicates, Empty)
{
	std::vector<int> v;
	auto result = stx::RemoveDuplicates(v.begin(), v.end());

	EXPECT_EQ(v.end(), result);
}

TEST(RemoveDuplicates, NoDuplicates)
{
	std::vector<int> v = { 1, 2, 3 };
	auto result = stx::RemoveDuplicates(v.begin(), v.end());

	EXPECT_EQ(v.end(), result);
	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(3, v[2]);
}

TEST(RemoveDuplicates, Single)
{
	std::vector<int> v = { 1, 2, 1, 3 };
	auto result = stx::RemoveDuplicates(v.begin(), v.end());

	EXPECT_EQ(v.begin() + 3, result);
	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(3, v[2]);
}

TEST(RemoveDuplicates, Multiple)
{
	std::vector<int> v = { 1, 1, 2, 1, 1, 1, 2, 1, 3 };
	auto result = stx::RemoveDuplicates(v.begin(), v.end());

	EXPECT_EQ(v.begin() + 3, result);
	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(3, v[2]);
}

TEST(RemoveDuplicates, AllSame)
{
	std::vector<int> v = { 1, 1, 1, 1};
	auto result = stx::RemoveDuplicates(v.begin(), v.end());

	EXPECT_EQ(v.begin() + 1, result);
	EXPECT_EQ(1, v[0]);
}

TEST(RemoveConsecutiveDuplicates, Empty)
{
	std::vector<int> v;
	auto result = stx::RemoveConsecutiveDuplicates(v.begin(), v.end());

	EXPECT_EQ(v.end(), result);
}

TEST(RemoveConsecutiveDuplicates, NoDuplicates)
{
	std::vector<int> v = { 1, 2, 3 };
	auto result = stx::RemoveConsecutiveDuplicates(v.begin(), v.end());

	EXPECT_EQ(v.end(), result);
	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(3, v[2]);
}

TEST(RemoveConsecutiveDuplicates, Single)
{
	std::vector<int> v = { 1, 2, 2, 3 };
	auto result = stx::RemoveConsecutiveDuplicates(v.begin(), v.end());

	EXPECT_EQ(v.begin() + 3, result);
	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(3, v[2]);
}

TEST(RemoveConsecutiveDuplicates, Multiple)
{
	std::vector<int> v = { 1, 1, 2, 2, 2, 2, 2, 3, 3 };
	auto result = stx::RemoveConsecutiveDuplicates(v.begin(), v.end());

	EXPECT_EQ(v.begin() + 3, result);
	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(3, v[2]);
}

TEST(RemoveConsecutiveDuplicates, MultipleUnordered)
{
	std::vector<int> v = { 1, 1, 2, 2, 2, 2, 2, 1, 1 };
	auto result = stx::RemoveConsecutiveDuplicates(v.begin(), v.end());

	EXPECT_EQ(v.begin() + 3, result);
	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(1, v[2]);
}

TEST(RemoveConsecutiveDuplicates, AllSame)
{
	std::vector<int> v = { 1, 1, 1, 1 };
	auto result = stx::RemoveConsecutiveDuplicates(v.begin(), v.end());

	EXPECT_EQ(v.begin() + 1, result);
	EXPECT_EQ(1, v[0]);
}

