#include <stx/algorithm/Move.h>
#include <gtest/gtest.h>
#include <vector>
#include <iterator>


static int MovedOutValue = -999;
struct Mint
{
	int Value;

	Mint(int Value)
		:
		Value(Value)
	{ }

	Mint(const Mint&) = default;
	Mint& operator=(const Mint&) = default;

	Mint(Mint&& other)
		:
		Value(other.Value)
	{ other.Value = MovedOutValue; }

	Mint& operator=(Mint&& other)
	{
		Value = other.Value;
		other.Value = MovedOutValue;
		return *this;
	}

	bool operator==(const Mint& other) const
	{
		return Value == other.Value;
	}

	bool operator!=(const Mint& other) const
	{
		return Value != other.Value;
	}

	operator int() const
	{
		return Value;
	}
};

TEST(Move, Empty)
{
	std::vector<Mint> v;
	std::vector<Mint> output(5, 0);
	auto result = stx::Move(v.begin(), v.end(), output.begin());

	EXPECT_EQ(output.begin(), result);
}

TEST(Move, Basic)
{
	std::vector<Mint> v = { 1, 2, 3 };
	std::vector<Mint> output(5, 0);
	auto result = stx::Move(v.begin(), v.end(), output.begin());

	EXPECT_EQ(output.begin() + v.size(), result);
	EXPECT_EQ(1, output[0]);
	EXPECT_EQ(2, output[1]);
	EXPECT_EQ(3, output[2]);
	EXPECT_EQ(MovedOutValue, v[0]);
	EXPECT_EQ(MovedOutValue, v[1]);
	EXPECT_EQ(MovedOutValue, v[2]);
}

TEST(Move, BasicOutputIterator)
{
	std::vector<Mint> v = { 1, 2, 3 };
	std::vector<Mint> output;
        stx::Move(v.begin(), v.end(), std::back_inserter(output));

	EXPECT_EQ(v.size(), output.size());
	EXPECT_EQ(1, output[0]);
	EXPECT_EQ(2, output[1]);
	EXPECT_EQ(3, output[2]);
	EXPECT_EQ(MovedOutValue, v[0]);
	EXPECT_EQ(MovedOutValue, v[1]);
	EXPECT_EQ(MovedOutValue, v[2]);
}

TEST(MoveN, Empty)
{
	std::vector<Mint> v;
	std::vector<Mint> output(5, 0);
	auto result = stx::MoveN(v.begin(), v.size(), output.begin());

	EXPECT_EQ(output.begin(), result);
}

TEST(MoveN, Basic)
{
	std::vector<Mint> v = { 1, 2, 3 };
	std::vector<Mint> output(5, 0);
	auto result = stx::MoveN(v.begin(), v.size(), output.begin());

	EXPECT_EQ(output.begin() + v.size(), result);
	EXPECT_EQ(1, output[0]);
	EXPECT_EQ(2, output[1]);
	EXPECT_EQ(3, output[2]);
	EXPECT_EQ(MovedOutValue, v[0]);
	EXPECT_EQ(MovedOutValue, v[1]);
	EXPECT_EQ(MovedOutValue, v[2]);
}

TEST(MoveBackward, Empty)
{
	std::vector<Mint> v;
	std::vector<Mint> output(5, 0);
	auto result = stx::MoveBackward(v.begin(), v.end(), output.end());

	EXPECT_EQ(output.end(), result);
}

TEST(MoveBackward, Basic)
{
	std::vector<Mint> v = { 1, 2, 3 };
	std::vector<Mint> output(5, 0);
	auto result = stx::MoveBackward(v.begin(), v.end(), output.end());

	EXPECT_EQ(output.end() - v.size(), result);
	EXPECT_EQ(1, output[2]);
	EXPECT_EQ(2, output[3]);
	EXPECT_EQ(3, output[4]);
	EXPECT_EQ(MovedOutValue, v[0]);
	EXPECT_EQ(MovedOutValue, v[1]);
	EXPECT_EQ(MovedOutValue, v[2]);
}

TEST(MoveIf, Empty)
{
	std::vector<Mint> v;
	std::vector<Mint> output(5, 0);
	auto result = stx::MoveIf(v.begin(), v.end(), output.begin(),
	                          [](Mint){ return true; });

	EXPECT_EQ(output.begin(), result);
}

TEST(MoveIf, Basic)
{
	std::vector<Mint> v = { 1, 2, 3 };
	std::vector<Mint> output(5, 0);
	auto result = stx::MoveIf(v.begin(), v.end(), output.begin(),
	                          [](Mint x){ return x.Value % 2 != 0; });

	EXPECT_EQ(output.begin() + 2, result);
	EXPECT_EQ(1, output[0]);
	EXPECT_EQ(3, output[1]);
	EXPECT_EQ(MovedOutValue, v[0]);
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(MovedOutValue, v[2]);
}

TEST(MoveIf, BasicOutputIterator)
{
	std::vector<Mint> v = { 1, 2, 3 };
	std::vector<Mint> output;
        stx::MoveIf(v.begin(), v.end(), std::back_inserter(output),
	                          [](Mint x){ return x.Value % 2 != 0; });

	EXPECT_EQ(std::vector<Mint>::size_type(2), output.size());
	EXPECT_EQ(1, output[0]);
	EXPECT_EQ(3, output[1]);
	EXPECT_EQ(MovedOutValue, v[0]);
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(MovedOutValue, v[2]);

}

TEST(MoveReversed, Empty)
{
	std::vector<Mint> v;
	std::vector<Mint> output(5, 0);
	auto result = stx::MoveReversed(v.begin(), v.end(), output.begin());

	EXPECT_EQ(output.begin(), result);
}

TEST(MoveReversed, Basic)
{
	std::vector<Mint> v = { 1, 2, 3 };
	std::vector<Mint> output(5, 0);
	auto result = stx::MoveReversed(v.begin(), v.end(), output.begin());

	EXPECT_EQ(output.begin() + v.size(), result);
	EXPECT_EQ(3, output[0]);
	EXPECT_EQ(2, output[1]);
	EXPECT_EQ(1, output[2]);
	EXPECT_EQ(MovedOutValue, v[0]);
	EXPECT_EQ(MovedOutValue, v[1]);
	EXPECT_EQ(MovedOutValue, v[2]);
}

TEST(MoveReversed, BasicOutputIterator)
{
	std::vector<Mint> v = { 1, 2, 3 };
	std::vector<Mint> output;
        stx::MoveReversed(v.begin(), v.end(), std::back_inserter(output));

	EXPECT_EQ(v.size(), output.size());
	EXPECT_EQ(3, output[0]);
	EXPECT_EQ(2, output[1]);
	EXPECT_EQ(1, output[2]);
	EXPECT_EQ(MovedOutValue, v[0]);
	EXPECT_EQ(MovedOutValue, v[1]);
	EXPECT_EQ(MovedOutValue, v[2]);

}

TEST(MoveReplaced, Empty)
{
	std::vector<Mint> v;
	std::vector<Mint> output(5, 0);
	auto result = stx::MoveReplaced(v.begin(), v.end(), output.begin(),
	                                [](Mint) { return true; }, -1);

	EXPECT_EQ(output.begin(), result);
}

TEST(MoveReplaced, Basic)
{
	std::vector<Mint> v = { 1, 2, 3 };
	std::vector<Mint> output(5, 0);
	auto result = stx::MoveReplaced(v.begin(), v.end(), output.begin(),
	                                [](Mint) { return true; }, -1);

	EXPECT_EQ(output.begin() + v.size(), result);
	EXPECT_EQ(-1, output[0]);
	EXPECT_EQ(-1, output[1]);
	EXPECT_EQ(-1, output[2]);
	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(3, v[2]);

}

TEST(MoveReplaced, BasicOutputIterator)
{
	std::vector<Mint> v = { 1, 2, 3 };
	std::vector<Mint> output;
        stx::MoveReplaced(v.begin(), v.end(), std::back_inserter(output),
	                  [](Mint x) { return x.Value % 2 == 0; }, -1 );

	EXPECT_EQ(v.size(), output.size());
	EXPECT_EQ(1, output[0]);
	EXPECT_EQ(-1, output[1]);
	EXPECT_EQ(3, output[2]);
	EXPECT_EQ(MovedOutValue, v[0]);
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(MovedOutValue, v[2]);

}

TEST(MoveRotated, EmptyBegin)
{
	std::vector<Mint> v;
	std::vector<Mint> output(5, 0);
	auto result = stx::MoveRotated(v.begin(), v.begin(), v.end(),
	                               output.begin());

	EXPECT_EQ(output.begin(), result);
}

TEST(MoveRotated, EmptyEnd)
{
	std::vector<Mint> v;
	std::vector<Mint> output(5, 0);
	auto result = stx::MoveRotated(v.begin(), v.end(), v.end(),
	                               output.begin());

	EXPECT_EQ(output.begin(), result);
}

TEST(MoveRotated, Basic)
{
	std::vector<Mint> v = { 1, 2, 3, 4, 5 };
	std::vector<Mint> output(5, 0);
	auto result = stx::MoveRotated(v.begin(), v.begin() + 3, v.end(),
	                               output.begin());

	EXPECT_EQ(output.begin() + v.size(), result);
	EXPECT_EQ(4, output[0]);
	EXPECT_EQ(5, output[1]);
	EXPECT_EQ(1, output[2]);
	EXPECT_EQ(2, output[3]);
	EXPECT_EQ(3, output[4]);
	EXPECT_EQ(MovedOutValue, v[0]);
	EXPECT_EQ(MovedOutValue, v[1]);
	EXPECT_EQ(MovedOutValue, v[2]);
	EXPECT_EQ(MovedOutValue, v[3]);
	EXPECT_EQ(MovedOutValue, v[4]);
}

TEST(MoveRotated, BasicOutputIterator)
{
	std::vector<Mint> v = { 1, 2, 3, 4, 5 };
	std::vector<Mint> output;
        stx::MoveRotated(v.begin(), v.begin() + 3, v.end(),
	                 std::back_inserter(output));

	EXPECT_EQ(v.size(), output.size());
	EXPECT_EQ(4, output[0]);
	EXPECT_EQ(5, output[1]);
	EXPECT_EQ(1, output[2]);
	EXPECT_EQ(2, output[3]);
	EXPECT_EQ(3, output[4]);
	EXPECT_EQ(MovedOutValue, v[0]);
	EXPECT_EQ(MovedOutValue, v[1]);
	EXPECT_EQ(MovedOutValue, v[2]);
	EXPECT_EQ(MovedOutValue, v[3]);
	EXPECT_EQ(MovedOutValue, v[4]);
}

