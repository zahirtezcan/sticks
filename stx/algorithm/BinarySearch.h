#ifndef STX_ALGORITHM_BINARYSEARCH_H
#define STX_ALGORITHM_BINARYSEARCH_H

#include <stx/Iterator.h>

namespace stx {

template<typename Iterator, typename T>
Iterator LowerBound(Iterator begin, Iterator end, const T& value)
{
	using std::distance;
	using std::advance;
	if (begin == end) {
		return end;
	}

	auto dist = distance(begin, end);

	while (dist > 0) {
		auto step = dist / 2;
		auto mid = begin;
		advance(mid, step);

		if (*mid < value) {
			begin = mid;
			advance(begin, 1);
			dist -= step + 1;
		} else {
			/*end = mid;*/
			dist = step;
		}
	}

	return begin;
}

template<typename Iterator, typename T>
Iterator UpperBound(Iterator begin, Iterator end, const T& value)
{
	using std::distance;
	using std::advance;
	if (begin == end) {
		return end;
	}

	auto dist = distance(begin, end);

	while (dist > 0) {
		auto step = dist / 2;
		auto mid = begin;
		advance(mid, step);

		if (value < *mid) {
			/*end = mid;*/
			dist = step;

		} else {
			begin = mid;
			advance(begin, 1);
			dist -= step + 1;
		}
	}

	return begin;
}


}

#endif

