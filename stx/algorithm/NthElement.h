#ifndef STX_ALGORITHM_NTHELEMENT_H
#define STX_ALGORITHM_NTHELEMENT_H

#include <stx/utility/Compare.h>

namespace stx {

template<typename Iterator, typename Compare>
void NthElement(Iterator /*begin*/, Iterator /*nth*/, Iterator /*end*/,
                Compare /*compare*/)
{
}

template<typename Iterator>
void NthElement(Iterator begin, Iterator nth, Iterator end)
{
	stx::NthElement(begin, nth, end, stx::Less());
}

} /* end of stx namespace */

#endif
