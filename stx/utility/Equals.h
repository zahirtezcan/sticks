#ifndef STX_UTILITY_EQUALS_H
#define STX_UTILITY_EQUALS_H

namespace stx {

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
