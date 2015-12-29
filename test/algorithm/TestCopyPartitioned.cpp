#include <stx/algorithm/CopyPartitioned.h>
#include <gtest/gtest.h>
#include <vector>
#include <iterator>

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

