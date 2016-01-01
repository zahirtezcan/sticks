#ifndef STX_ALGORITHM_EQUALRANGE_H
#define STX_ALGORITHM_EQUALRANGE_H

#include <utility>
#include <stx/utility/Compare.h>
#include <stx/algorithm/LowerBound.h>
#include <stx/algorithm/UpperBound.h>

namespace stx {

template<typename Iterator, typename T, typename Compare>
std::pair<Iterator, Iterator> EqualRange(Iterator begin, Iterator end,
                                         const T& value,
                                         Compare&& compare)
{
	return { LowerBound(begin, end, value, std::forward<Compare>(compare)),
	         UpperBound(begin, end, value, std::forward<Compare>(compare)) };
}

template<typename Iterator, typename T>
std::pair<Iterator, Iterator> EqualRange(Iterator begin, Iterator end,
                                         const T& value)
{
	return stx::EqualRange(begin, end, value, stx::Less());
}

}/*end of stx namespace*/

#endif

