#include <stx/algorithm/InnerProduct.h>
#include <gtest/gtest.h>
#include <vector>

TEST(InnerProduct, Empty)
{
	std::vector<int> v;
	std::vector<int> u;
	int init = 0;

	int result = stx::InnerProduct(v.begin(), v.end(), u.begin(), u.end(), init);

	EXPECT_EQ(0, result);
}

TEST(InnerProduct, EmptyFirst)
{
	std::vector<int> v;
	std::vector<int> u = { 1, 2, 3 };
	int init = 0;

	int result = stx::InnerProduct(v.begin(), v.end(), u.begin(), u.end(), init);

	EXPECT_EQ(0, result);
}

TEST(InnerProduct, EmptySecond)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> u;
	int init = 0;

	int result = stx::InnerProduct(v.begin(), v.end(), u.begin(), u.end(), init);

	EXPECT_EQ(0, result);
}

TEST(InnerProduct, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> u = { 1, 2, 3 };
	int init = 0;

	int result = stx::InnerProduct(v.begin(), v.end(), u.begin(), u.end(), init);

	EXPECT_EQ(14, result);
}
