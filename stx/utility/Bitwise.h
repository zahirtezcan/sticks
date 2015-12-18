#ifndef STX_UTILITY_BITWISE_H
#define STX_UTILITY_BITWISE_H

namespace stx {

struct BitwiseAnd
{
	template<typename T, typename U>
	constexpr auto operator()(const T& t, const U& u) const
	{
		return t & u;
	}
};

struct BitwiseOr
{
	template<typename T, typename U>
	constexpr auto operator()(const T& t, const U& u) const
	{
		return t | u;
	}
};

struct BitwiseXor
{
	template<typename T, typename U>
	constexpr auto operator()(const T& t, const U& u) const
	{
		return t ^ u;
	}
};

struct BitwiseNot
{
	template<typename T, typename U>
	constexpr auto operator()(const T& t) const
	{
		return ~t;
	}
};

}

#endif
