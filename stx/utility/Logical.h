#ifndef STX_UTILITY_LOGICAL_H
#define STX_UTILITY_LOGICAL_H

namespace stx {

struct LogicalAnd
{
	template<typename T, typename U>
	constexpr bool operator()(const T& t, const U& u) const
	{
		return t && u;
	}
};

struct LogicalOr
{
	template<typename T, typename U>
	constexpr bool operator()(const T& t, const U& u) const
	{
		return t || u;
	}
};

struct LogicalNot
{
	template<typename T, typename U>
	constexpr bool operator()(const T& t) const
	{
		return !t;
	}
};

}

#endif
