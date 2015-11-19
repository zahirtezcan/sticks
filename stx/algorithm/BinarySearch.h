#ifndef STX_ALGORITHM_BINARYSEARCH_H
#define STX_ALGORITHM_BINARYSEARCH_H

#include <utility>
#include <stx/Iterator.h>
#include <stx/utility/Compare.h>

namespace stx {

template<typename Iterator, typename T, typename Compare>
Iterator LowerBound(Iterator begin, Iterator end,
                    const T& value,
                    Compare compare)
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

		if (compare(*mid, value)) {
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
Iterator LowerBound(Iterator begin, Iterator end, const T& value)
{
	return stx::LowerBound(begin, end, value, stx::Less());
}

template<typename Iterator, typename T, typename Compare>
bool BinarySearch(Iterator begin, Iterator end,
                  const T& value,
                  Compare compare)
{
	auto found = stx::LowerBound(begin, end, value, compare);
	return found != end && !compare(value, *begin);
}

template<typename Iterator, typename T>
bool BinarySearch(Iterator begin, Iterator end,
                  const T& value)
{
	return BinarySearch(begin, end, value, stx::Less());
}

template<typename Iterator, typename T, typename Compare>
Iterator UpperBound(Iterator begin, Iterator end,
                    const T& value,
                    Compare compare)
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

		if (compare(value, *mid)) {
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

template<typename Iterator, typename T>
Iterator UpperBound(Iterator begin, Iterator end, const T& value)
{
	return stx::UpperBound(begin, end, value, stx::Less());
}

template<typename Iterator, typename T, typename Compare>
std::pair<Iterator, Iterator> EqualRange(Iterator begin, Iterator end,
                                         const T& value,
                                         Compare compare)
{
	return { LowerBound(begin, end, value, compare),
	         UpperBound(begin, end, value, compare) };
}

template<typename Iterator, typename T>
std::pair<Iterator, Iterator> EqualRange(Iterator begin, Iterator end,
                                         const T& value)
{
	return stx::EqualRange(begin, end, value, stx::Less());
}

}/*end of stx namespace*/

#endif

