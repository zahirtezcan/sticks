#ifndef STX_UTILITY_ARITHMETIC_H
#define STX_UTILITY_ARITHMETIC_H

namespace stx {

struct Add
{
	template<typename T, typename U>
	constexpr auto operator()(const T& t, const U& u) const
	{
		return t + u;
	}
};

struct Subtract
{
	template<typename T, typename U>
	constexpr auto operator()(const T& t, const U& u) const
	{
		return t - u;
	}
};

struct Multiply
{
	template<typename T, typename U>
	constexpr auto operator()(const T& t, const U& u) const
	{
		return t * u;
	}
};

struct Divide
{
	template<typename T, typename U>
	constexpr auto operator()(const T& t, const U& u) const
	{
		return t / u;
	}
};

struct Modulus
{
	template<typename T, typename U>
	constexpr auto operator()(const T& t, const U& u) const
	{
		return t % u;
	}
};

struct Negate
{
	template<typename T>
	constexpr auto operator()(const T& t) const
	{
		return -t;
	}
};

} /* end of stx namespace */

#endif

