#include <stx/algorithm/Transform.h>
#include <gtest/gtest.h>
#include <vector>
#include <cmath>

TEST(Transform, Empty)
{
	std::vector<int> v;
	std::vector<int> output(100, 0);

	auto result = stx::Transform(v.begin(), v.end(), output.begin(), [](int) { return -1; });

	EXPECT_EQ(0, output[0]);
	EXPECT_EQ(output.begin(), result);
}

TEST(Transform, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(100, 0);

	auto result = stx::Transform(v.begin(), v.end(), output.begin(), [](int x) { return x; });

	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[1], output[1]);
	EXPECT_EQ(v[2], output[2]);
	EXPECT_EQ(output.begin() + v.size(), result);
}

TEST(Transform, Cast)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<double> output(100, 0.0);

	auto result = stx::Transform(v.begin(), v.end(), output.begin(), [](int x) { return static_cast<double>(x); });

	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[1], output[1]);
	EXPECT_EQ(v[2], output[2]);
	EXPECT_EQ(output.begin() + v.size(), result);
}

TEST(TransformIndexed, Empty)
{
	std::vector<int> v;
	std::vector<int> output(100, 0);

	auto result = stx::TransformIndexed(v.begin(), v.end(), output.begin(), [](int, int) { return -1; });

	EXPECT_EQ(0, output[0]);
	EXPECT_EQ(output.begin(), result);
}

TEST(TransformIndexed, BasicNoIndex)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(100, 0);

	auto result = stx::TransformIndexed(v.begin(), v.end(), output.begin(), [](int x, int) { return x; });

	EXPECT_EQ(v[0], output[0]);
	EXPECT_EQ(v[1], output[1]);
	EXPECT_EQ(v[2], output[2]);
	EXPECT_EQ(output.begin() + v.size(), result);
}

TEST(TransformIndexed, Basic)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<int> output(100, -1);

	auto result = stx::TransformIndexed(v.begin(), v.end(), output.begin(), [](int, int index) { return index; });

	EXPECT_EQ(0, output[0]);
	EXPECT_EQ(1, output[1]);
	EXPECT_EQ(2, output[2]);
	EXPECT_EQ(output.begin() + v.size(), result);
}

TEST(TransformIndexed, Power)
{
	std::vector<int> v = { 1, 2, 3 };
	std::vector<double> output(100, 0.0);

	auto result = stx::TransformIndexed(v.begin(), v.end(), output.begin(), [](int x, int index) { return std::pow(x, index); });

	EXPECT_EQ(1, output[0]);
	EXPECT_EQ(2, output[1]);
	EXPECT_EQ(9, output[2]);
	EXPECT_EQ(output.begin() + v.size(), result);
}

