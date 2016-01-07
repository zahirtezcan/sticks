#ifndef STX_ALGORITHM_FIND_H
#define STX_ALGORITHM_FIND_H

#include <utility>
#include <stx/utility/Equals.h>

namespace stx {

template<typename Iterator, typename UnaryPredicate>
Iterator Find(Iterator begin, Iterator end, UnaryPredicate&& check)
{
	while (begin != end) {
		if (std::forward<UnaryPredicate>(check)(*begin)) {
			return begin;
		}

		++begin;
	}

	return end;
}

template<typename Iterator, typename T>
Iterator FindValue(Iterator begin, Iterator end, const T& value)
{
	while (begin != end) {
		if (*begin == value) {
			return begin;
		}

		++begin;
	}

	return end;
}

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

