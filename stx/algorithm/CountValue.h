#ifndef STX_ALGORITHM_COUNTVALUE_H
#define STX_ALGORITHM_COUNTVALUE_H

#include <stx/algorithm/Count.h>

namespace stx {

template<typename Iterator, typename T>
stx::IteratorDifference<Iterator> CountValue(Iterator begin, Iterator end,
                                             const T& value)
{
	return Count(begin, end,
	             [&] (const auto& iv) { return iv == value; });
}

} /* end of stx namespace */

#endif
