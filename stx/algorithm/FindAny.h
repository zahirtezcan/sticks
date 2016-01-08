#ifndef STX_ALGORITHM_FIND_H
#define STX_ALGORITHM_FIND_H

#include <utility>
#include <stx/utility/Equals.h>

namespace stx {

template<typename Iterator, typename ValueIterator, typename BinaryPredicate>
Iterator FindAny(Iterator begin, Iterator end,
                 ValueIterator valueBegin, ValueIterator valueEnd,
                 BinaryPredicate&& equals)
{
	while (begin != end) {
		auto valueIter = valueBegin;
		while (valueIter != valueEnd) {
			if (std::forward<BinaryPredicate>(equals)(*begin, *valueIter)) {
				return begin;
			}
			++valueIter;
		}

		++begin;
	}

	return end;
}

template<typename Iterator, typename ValueIterator>
Iterator FindAny(Iterator begin, Iterator end,
                 ValueIterator valueBegin, ValueIterator valueEnd)
{	
	return FindAny(begin, end, valueBegin, valueEnd, stx::Equals());
}

}/*end of stx namespace*/

#endif

