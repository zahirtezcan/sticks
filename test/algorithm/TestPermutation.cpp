#include <stx/algorithm/Permutation.h>
#include <gtest/gtest.h>
#include <vector>

TEST(NextPermutation, Empty)
{
	std::vector<int> v;

	auto result = stx::NextPermutation(v.begin(), v.end());

	EXPECT_FALSE(result);
}

TEST(NextPermutation, Single)
{
	std::vector<int> v = { 1 };

	auto result = stx::NextPermutation(v.begin(), v.end());

	EXPECT_FALSE(result);
	EXPECT_EQ(1, v[0]);
}

TEST(NextPermutation, Basic)
{
	std::vector<int> v = { 1, 2 };

	auto result = stx::NextPermutation(v.begin(), v.end());

	EXPECT_TRUE(result);
	EXPECT_EQ(2, v[0]);
	EXPECT_EQ(1, v[1]);

	result = stx::NextPermutation(v.begin(), v.end());

	EXPECT_FALSE(result);
	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
}

TEST(NextPermutation, FiveElements)
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	std::vector<int> u = v;
	int count = 1;
	while (stx::NextPermutation(u.begin(), u.end())) {
		auto isPerm = stx::IsPermutation(u.begin(), u.end(),
		                                 v.begin(), v.end());
		EXPECT_TRUE(isPerm);
		++count;
	}

	EXPECT_EQ(120, count);// 120 = 5!
	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(3, v[2]);
	EXPECT_EQ(4, v[3]);
	EXPECT_EQ(5, v[4]);

}

TEST(PreviousPermutation, Empty)
{
	std::vector<int> v;

	auto result = stx::PreviousPermutation(v.begin(), v.end());

	EXPECT_FALSE(result);
}

TEST(PreviousPermutation, Single)
{
	std::vector<int> v = { 1 };

	auto result = stx::PreviousPermutation(v.begin(), v.end());

	EXPECT_FALSE(result);
	EXPECT_EQ(1, v[0]);
}

TEST(PreviousPermutation, Basic)
{
	std::vector<int> v = { 1, 2 };

	auto result = stx::PreviousPermutation(v.begin(), v.end());

	EXPECT_FALSE(result);
	EXPECT_EQ(2, v[0]);
	EXPECT_EQ(1, v[1]);

	result = stx::PreviousPermutation(v.begin(), v.end());

	EXPECT_TRUE(result);
	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
}

TEST(PreviousPermutation, FiveElements)
{
	std::vector<int> v = { 5, 4, 3, 2, 1 };
	std::vector<int> u = v;
	int count = 1;
	while (stx::PreviousPermutation(u.begin(), u.end())) {
		auto isPerm = stx::IsPermutation(u.begin(), u.end(),
		                                 v.begin(), v.end());
		EXPECT_TRUE(isPerm);
		++count;
	}

	EXPECT_EQ(120, count);// 120 = 5!
	EXPECT_EQ(5, v[0]);
	EXPECT_EQ(4, v[1]);
	EXPECT_EQ(3, v[2]);
	EXPECT_EQ(2, v[3]);
	EXPECT_EQ(1, v[4]);

}

TEST(IsPermutation, Empty)
{
	std::vector<int> v;
	std::vector<int> u;

	auto isp = stx::IsPermutation(v.begin(), v.end(), u.begin(), u.end());
	
	EXPECT_TRUE(isp);
}

TEST(IsPermutation, EmptyFirst)
{
	std::vector<int> v;
	std::vector<int> u = { 1 };

	auto isp = stx::IsPermutation(v.begin(), v.end(), u.begin(), u.end());
	
	EXPECT_FALSE(isp);
}

TEST(IsPermutation, EmptySecond)
{
	std::vector<int> v = { 1 };
	std::vector<int> u;

	auto isp = stx::IsPermutation(v.begin(), v.end(), u.begin(), u.end());
	
	EXPECT_FALSE(isp);
}

TEST(IsPermutation, Single)
{
	std::vector<int> v = { 1 };
	std::vector<int> u = { 1 };

	auto isp = stx::IsPermutation(v.begin(), v.end(), u.begin(), u.end());
	
	EXPECT_TRUE(isp);
}

TEST(IsPermutation, SingleDifferent)
{
	std::vector<int> v = { 1 };
	std::vector<int> u = { 2 };

	auto isp = stx::IsPermutation(v.begin(), v.end(), u.begin(), u.end());
	
	EXPECT_FALSE(isp);
}

TEST(IsPermutation, ThreeElements)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> u1 = { 1, 2, 3 };
	std::vector<int> u2 = { 1, 2, 3 };
	std::vector<int> u3 = { 1, 2, 3 };
	std::vector<int> u4 = { 1, 2, 3 };
	std::vector<int> u5 = { 1, 2, 3 };
	std::vector<int> u6 = { 1, 2, 3 };
	std::vector<int> y = { 3, 2, 3 };

	auto isp = stx::IsPermutation(v.begin(), v.end(), u1.begin(), u1.end());
	EXPECT_TRUE(isp);
	isp = stx::IsPermutation(v.begin(), v.end(), u2.begin(), u2.end());
	EXPECT_TRUE(isp);
	isp = stx::IsPermutation(v.begin(), v.end(), u3.begin(), u3.end());
	EXPECT_TRUE(isp);
	isp = stx::IsPermutation(v.begin(), v.end(), u4.begin(), u4.end());
	EXPECT_TRUE(isp);
	isp = stx::IsPermutation(v.begin(), v.end(), u5.begin(), u5.end());
	EXPECT_TRUE(isp);
	isp = stx::IsPermutation(v.begin(), v.end(), u6.begin(), u6.end());
	EXPECT_TRUE(isp);
	isp = stx::IsPermutation(v.begin(), v.end(), y.begin(), y.end());
	EXPECT_FALSE(isp);
}

