#include <stx/algorithm/Copy.h>
#include <gtest/gtest.h>
#include <vector>

TEST(Copy, Empty)
{
	std::vector<int> v;
	std::vector<int> output(5, 0);
	auto result = stx::Copy(v.begin(), v.end(), output.begin());

	EXPECT_EQ(output.begin(), result);
}
