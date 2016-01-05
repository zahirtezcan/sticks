#ifndef STX_ALGORITHM_FINDREPITITION_H
#define STX_ALGORITHM_FINDREPITITION_H

#include <utility>
#include <stx/utility/Equals.h>

namespace stx {

template<typename Iterator, typename Size, typename T, typename BinaryPredicate>
Iterator FindRepitition(Iterator begin, Iterator end,
                        Size count, const T& value,
			BinaryPredicate&& equals)
{
	while (begin != end) {
		auto srcIter = begin;
		
		Size thisCount = 0;
		while (true) {
			if (thisCount == count) {
				return begin;
			} else if (srcIter == end) {
				return end;
			} else if (!std::forward<BinaryPredicate>(equals)(*srcIter, value)) {
				begin = srcIter;
				break;
			}

			++thisCount;
			++srcIter;
		}

		++begin;
	}

	return end;
}

template<typename Iterator, typename Size, typename T>
Iterator FindRepitition(Iterator begin, Iterator end,
                        Size count, const T& value)
{
	return FindRepitition(begin, end, count, value, stx::Equals());
}

}/*end of stx namespace*/

#endif

