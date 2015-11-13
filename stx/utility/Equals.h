#ifndef STX_UTILITY_EQUALS_H
#define STX_UTILITY_EQUALS_H

namespace stx {

struct Equals;
struct NotEquals;

namespace detail {

template<typename Iterator, typename BinaryPredicate = stx::Equals>
struct EqualsPointee
{
	Iterator iter;
	BinaryPredicate equals;

	EqualsPointee(Iterator iter, BinaryPredicate equals)
		:
		iter(iter),
		equals(equals)
	{}

	template<typename T>
	bool operator()(const T& other)
	{
		return equals(*iter,  other);
	}
};

}/*end of stx::detail namespace*/

struct Equals
{
	template<typename T, typename U>
	constexpr bool operator()(const T& t, const U& u) const
	{
		return t == u;
	}
};

struct NotEquals
{
	template<typename T, typename U>
	constexpr bool operator()(const T& t, const U& u) const
	{
		return t != u;
	}
};

}/*end of stx namespace*/

#endif
