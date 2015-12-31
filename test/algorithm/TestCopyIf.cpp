#include <stx/algorithm/CopyIf.h>
#include <gtest/gtest.h>
#include <vector>
#include <iterator>

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

