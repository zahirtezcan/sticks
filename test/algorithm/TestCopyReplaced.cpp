#include <stx/algorithm/CopyReplaced.h>
#include <gtest/gtest.h>
#include <vector>
#include <iterator>

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

