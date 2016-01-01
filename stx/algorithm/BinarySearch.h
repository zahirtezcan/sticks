#ifndef STX_ALGORITHM_BINARYSEARCH_H
#define STX_ALGORITHM_BINARYSEARCH_H

#include <utility>
#include <stx/utility/Compare.h>
#include <stx/algorithm/LowerBound.h>

namespace stx {

template<typename Iterator, typename T, typename Compare>
bool BinarySearch(Iterator begin, Iterator end,
                  const T& value,
                  Compare&& compare)
{
	auto found = stx::LowerBound(begin, end, value, compare);
	return found != end && !std::forward<Compare>(compare)(value, *begin);
}

template<typename Iterator, typename T>
bool BinarySearch(Iterator begin, Iterator end,
                  const T& value)
{
	return BinarySearch(begin, end, value, stx::Less());
}

}/*end of stx namespace*/

#endif

