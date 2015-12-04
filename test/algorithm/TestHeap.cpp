#include <stx/algorithm/Heap.h>
#include <gtest/gtest.h>
#include <vector>

TEST(IsHeap, Empty)
{
	std::vector<int> v;
	
	bool result = stx::IsHeap(v.begin(), v.end());

	EXPECT_TRUE(result);
}

TEST(IsHeap, One)
{
	std::vector<int> v = { 1 };
	
	bool result = stx::IsHeap(v.begin(), v.end());

	EXPECT_TRUE(result);
}

TEST(IsHeap, Basic)
{
	std::vector<int> v = { 5, 4, 3, 2, 1 };
	
	bool result = stx::IsHeap(v.begin(), v.end());

	EXPECT_TRUE(result);
}

TEST(IsHeap, BasicFalse)
{
	std::vector<int> v = { 1, 4, 3, 2, 5 };
	
	bool result = stx::IsHeap(v.begin(), v.end());

	EXPECT_FALSE(result);
}

TEST(FindHeapEnd, Empty)
{
	std::vector<int> v;
	
	auto result = stx::FindHeapEnd(v.begin(), v.end());

	EXPECT_EQ(v.end(), result);
}

TEST(FindHeapEnd, One)
{
	std::vector<int> v = { 1 };
	
	auto result = stx::FindHeapEnd(v.begin(), v.end());

	EXPECT_EQ(v.end(), result);
}

TEST(FindHeapEnd, Basic)
{
	std::vector<int> v = { 5, 4, 3, 2, 1 };
	
	auto result = stx::FindHeapEnd(v.begin(), v.end());

	EXPECT_EQ(v.end(), result);
}

TEST(FindHeapEnd, BasicFalse)
{
	std::vector<int> v = { 1, 4, 3, 2, 5 };
	
	auto result = stx::FindHeapEnd(v.begin(), v.end());

	EXPECT_EQ(v.begin() + 1, result);
}

TEST(PushHeap, Empty)
{
	std::vector<int> v;
	
	stx::PushHeap(v.begin(), v.end());

	EXPECT_TRUE(v.empty());
}

TEST(PushHeap, One)
{
	std::vector<int> v = { 1 };
	
	stx::PushHeap(v.begin(), v.end());

	EXPECT_EQ(std::vector<int>::size_type(1), v.size());
	EXPECT_EQ(1, v[0]);
}

TEST(PushHeap, Basic)
{
	std::vector<int> v = { 4, 3, 2, 1, 5 };
	
	EXPECT_FALSE(stx::IsHeap(v.begin(), v.end()));
	
	stx::PushHeap(v.begin(), v.end());
	
	EXPECT_TRUE(stx::IsHeap(v.begin(), v.end()));
}

TEST(PopHeap, Empty)
{
	std::vector<int> v;
	
	stx::PopHeap(v.begin(), v.end());

	EXPECT_TRUE(v.empty());
}

TEST(PopHeap, One)
{
	std::vector<int> v = { 1 };
	
	stx::PopHeap(v.begin(), v.end());

	EXPECT_EQ(std::vector<int>::size_type(1), v.size());
	EXPECT_EQ(1, v[0]);
}

TEST(PopHeap, Basic)
{
	std::vector<int> v = { 5, 4, 3, 2, 1 };
	
	EXPECT_TRUE(stx::IsHeap(v.begin(), v.end()));
	
	stx::PopHeap(v.begin(), v.end());
	EXPECT_EQ(v.end() - 1, stx::FindHeapEnd(v.begin(), v.end()));
	EXPECT_EQ(5, v.back());
}

TEST(SortHeap, Empty)
{
	std::vector<int> v;
	
	stx::SortHeap(v.begin(), v.end());

	EXPECT_TRUE(v.empty());
}

TEST(SortHeap, One)
{
	std::vector<int> v = { 1 };
	
	stx::SortHeap(v.begin(), v.end());

	EXPECT_EQ(std::vector<int>::size_type(1), v.size());
	EXPECT_EQ(1, v[0]);
}

TEST(SortHeap, Basic)
{
	std::vector<int> v = { 5, 4, 3, 2, 1 };
	
	EXPECT_TRUE(stx::IsHeap(v.begin(), v.end()));
	
	stx::SortHeap(v.begin(), v.end());
	
	EXPECT_EQ(v.begin() + 1, stx::FindHeapEnd(v.begin(), v.end()));
	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(3, v[2]);
	EXPECT_EQ(4, v[3]);
	EXPECT_EQ(5, v[4]);
}

TEST(MakeHeap, Empty)
{
	std::vector<int> v;
	
	stx::MakeHeap(v.begin(), v.end());

	EXPECT_TRUE(v.empty());
}

TEST(MakeHeap, One)
{
	std::vector<int> v = { 1 };
	
	stx::MakeHeap(v.begin(), v.end());

	EXPECT_EQ(std::vector<int>::size_type(1), v.size());
	EXPECT_EQ(1, v[0]);
}

TEST(MakeHeap, Two)
{
	std::vector<int> v = { 1, 2 };
	
	stx::MakeHeap(v.begin(), v.end());

	EXPECT_EQ(2, v[0]);
	EXPECT_EQ(1, v[1]);
}

TEST(MakeHeap, Basic)
{
	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	
	EXPECT_FALSE(stx::IsHeap(v.begin(), v.end()));

	stx::MakeHeap(v.begin(), v.end());
	
	EXPECT_TRUE(stx::IsHeap(v.begin(), v.end()));
}

