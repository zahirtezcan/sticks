#ifndef STX_ALGORITHM_COUNT_H
#define STX_ALGORITHM_COUNT_H

#include <utility>
#include <stx/utility/Iterator.h>

namespace stx {

template<typename Iterator, typename UnaryPredicate>
stx::IteratorDifference<Iterator> Count(Iterator begin, Iterator end,
                                        UnaryPredicate&& check)
{
	stx::IteratorDifference<Iterator> count = 0;

	while (begin != end) {
		if (std::forward<UnaryPredicate>(check)(*begin)) {
			++count;
		}

		++begin;
	}

	return count;
}

} /* end of stx namespace */

#endif
