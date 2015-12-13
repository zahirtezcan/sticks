#ifndef STX_ALGORITHM_STABLE_SORT_H
#ifndef STX_ALGORITHM_STABLE_SORT_H

#include <stx/utility/Compare.h>

namespace stx {

template<typename Iterator, typename Compare>
void StableSort(Iterator begin, Iterator end, Compare compare)
{
}

template<typename Iterator>
void StableSort(Iterator begin, Iterator end)
{
	stx::StableSort(begin, end, stx::Less());
}

} /* end of stx namespace */

#endif
