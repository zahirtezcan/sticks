#ifndef STX_ALGORITHM_FINDLASTSEQUENCE_H
#define STX_ALGORITHM_FINDLASTSEQUENCE_H

#include <utility>
#include <stx/utility/Equals.h>
#include <stx/algorithm/FindSequence.h>

namespace stx {

template<typename Iterator, typename ValueIterator, typename BinaryPredicate>
Iterator FindLastSequence(Iterator begin, Iterator end,
                          ValueIterator seqBegin, ValueIterator seqEnd,
                          BinaryPredicate&& equals)
{
	/*TODO: If iterators are bidirectional, we can just use one FindSequence with reverese iterators*/
	if (seqBegin == seqEnd) {
		return end;
	}

	auto result = end;

	while (true) {
		auto current = stx::FindSequence(begin, end, seqBegin, seqEnd,
		                                 std::forward<BinaryPredicate>(equals));

		if (current == end) {
			break;
		} else {
			result = current;
			begin = current;
			++begin;
		}
	}

	return result;
}

template<typename Iterator, typename ValueIterator>
Iterator FindLastSequence(Iterator begin, Iterator end,
                          ValueIterator seqBegin, ValueIterator seqEnd)
{
	return FindLastSequence(begin, end, seqBegin, seqEnd, stx::Equals());
}

}/*end of stx namespace*/

#endif

