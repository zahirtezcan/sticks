#ifndef STX_ALGORITHM_SWAPRANGES_H
#define STX_ALGORITHM_SWAPRANGES_H

#include <utility>
#include <stx/algorithm/SwapPointee.h>

namespace stx {

template<typename Iterator1, typename Iterator2>
std::pair<Iterator1, Iterator2> SwapRanges(Iterator1 begin1, Iterator1 end1,
                                           Iterator2 begin2, Iterator2 end2)
{
	while (begin1 != end1 && begin2 != end2) {
		stx::SwapPointee(begin1, begin2);
		++begin1;
		++begin2;
	}

	return { begin1, begin2 };
}

}

#endif

