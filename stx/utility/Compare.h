#ifndef STX_UTILITY_COMPARE_H
#define STX_UTILITY_COMPARE_H

namespace stx {

struct Less
{
	template<typename T, typename U>
	bool operator()(const T& t, const U& u) const
	{
		return t < u;
	}
};

struct LessOrEqual
{
	template<typename T, typename U>
	bool operator()(const T& t, const U& u) const
	{
		return t <= u;
	}
};

struct Greater
{
	template<typename T, typename U>
	bool operator()(const T& t, const U& u) const
	{
		return t > u;
	}
};

struct GreaterOrEqual
{
	template<typename T, typename U>
	bool operator()(const T& t, const U& u) const
	{
		return t >= u;
	}
};


}

#endif
