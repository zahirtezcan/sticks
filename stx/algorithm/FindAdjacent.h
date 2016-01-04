#ifndef STX_ALGORITHM_FINDADJACENT_H
#define STX_ALGORITHM_FINDADJACENT_H

#include <utility>
#include <stx/utility/Equals.h>

namespace stx {

template<typename Iterator, typename BinaryPredicate>
Iterator FindAdjacent(Iterator begin, Iterator end, BinaryPredicate&& equals)
{
	if (begin == end) {
		return end;
	}

	auto next = begin;
	++next;
	while (next != end) {
		if (std::forward<BinaryPredicate>(equals)(*begin, *next)) {
			return begin;
		}
		++begin;
		++next;
	}

	return end;
}

template<typename Iterator>
Iterator FindAdjacent(Iterator begin, Iterator end)
{
	return FindAdjacent(begin, end, stx::Equals());
}

}/*end of stx namespace*/

#endif

