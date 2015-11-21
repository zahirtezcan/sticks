#ifndef STX_ALGORITHM_MINMAX_H
#define STX_ALGORITHM_MINMAX_H

#include <utility>
#include <stx/utility/Compare.h>

namespace stx {

template<typename T, typename Compare>
const T& Min(const T& x, const T& y, Compare compare)
{
	return compare(y, x) ? y : x;
}

template<typename T>
const T& Min(const T& x, const T& y)
{
	return Min(x, y, stx::Less());
}

template<typename T, typename Compare>
const T& Max(const T& x, const T& y, Compare compare)
{
	return compare(x, y) ? y : x;
}

template<typename T>
const T& Max(const T& x, const T& y)
{
	return Max(x, y, stx::Less());
}

template<typename Iterator, typename Compare>
Iterator MinElement(Iterator begin, Iterator end, Compare compare)
{
	if (begin == end) {
		return end;
	}

	auto result = begin;
	++begin;
	while (begin != end) {
		if (compare(*begin, *result)) {
			result = begin;
		}
		++begin;
	}

	return result;
}

template<typename Iterator>
Iterator MinElement(Iterator begin, Iterator end)
{
	return MinElement(begin, end, stx::Less());
}

template<typename Iterator, typename Compare>
Iterator MaxElement(Iterator begin, Iterator end, Compare compare)
{
	if (begin == end) {
		return end;
	}

	auto result = begin;
	++begin;
	while (begin != end) {
		if (compare(*result, *begin)) {
			result = begin;
		}
		++begin;
	}

	return result;
}

template<typename Iterator>
Iterator MaxElement(Iterator begin, Iterator end)
{
	return MaxElement(begin, end, stx::Less());
}

template<typename T, typename Compare>
std::pair<const T&, const T&> MinMax(const T& x, const T& y, Compare compare)
{
	if (compare(y, x)) {
		return { y, x };
	} else {
		return { x, y };
	}
}

template<typename T>
std::pair<const T&, const T&> MinMax(const T& x, const T& y)
{
	return stx::MinMax(x, y, stx::Less());
}

template<typename Iterator, typename Compare>
std::pair<Iterator, Iterator> MinMaxElement(Iterator begin, Iterator end,
                                            Compare compare)
{
	std::pair<Iterator, Iterator> minmax = { begin, begin };
	if (begin == end) {
		return { end, end };
	} else if (++begin == end) {
		return minmax;
	} else if (compare(*begin, minmax.first)) {
		minmax.first = begin;
	} else {
		minmax.second = begin;
	}

	while (++begin != end) {
		Iterator current = begin;
		++begin;
		if (begin == end) {
			if (compare(*current, *minmax.first)) {
				minmax.first = current;
			} else if (!compare(*current, *minmax.second)) {
				minmax.second = current;
			}
			break;
		} else if (compare(*current, *begin)) {
			if (compare(*current, *minmax.first)) {
				minmax.first = current;
			}
			if (!compare(*begin, *minmax.second)) {
				minmax.second = begin;
			}
		} else {
			if (compare(*begin, *minmax.first)) {
				minmax.first = begin;
			}
			if (!compare(*current, *minmax.second)) {
				minmax.second = current;
			}
		}
	}

	return minmax;
}

template<typename Iterator>
std::pair<Iterator, Iterator> MinMaxElement(Iterator begin, Iterator end)
{
	return stx::MinMaxElement(begin, end, stx::Less());
}

}/*end of stx namespace*/

#endif
