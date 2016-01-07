#ifndef STX_ALGORITHM_FINDSEQUENCE_H
#define STX_ALGORITHM_FINDSEQUENCE_H

#include <utility>
#include <stx/utility/Equals.h>

namespace stx {

template<typename Iterator, typename ValueIterator, typename BinaryPredicate>
Iterator FindSequence(Iterator begin, Iterator end,
                      ValueIterator seqBegin, ValueIterator seqEnd,
                      BinaryPredicate&& equals)
{
	while (begin != end) {
		auto srcIter = begin;
		
		auto seqIter = seqBegin;
		while (true) {
			if (seqIter == seqEnd) {
				return begin;
			} else if (srcIter == end) {
				return end;
			} else if (!std::forward<BinaryPredicate>(equals)(*srcIter, *seqIter)) {
				break;
			}

			++seqIter;
			++srcIter;
		}

		++begin;
	}

	return end;
}

template<typename Iterator, typename ValueIterator>
Iterator FindSequence(Iterator begin, Iterator end,
                      ValueIterator seqBegin, ValueIterator seqEnd)
{
	/* known as "search" in STL */
	return FindSequence(begin, end, seqBegin, seqEnd, stx::Equals());	
}

}/*end of stx namespace*/

#endif

