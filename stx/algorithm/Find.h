#ifndef STX_ALGORITHM_FIND_H
#define STX_ALGORITHM_FIND_H

#include <stx/utility/Equals.h>

namespace stx {

template<typename Iterator, typename UnaryPredicate>
Iterator Find(Iterator begin, Iterator end, UnaryPredicate check)
{
	while (begin != end) {
		if (check(*begin)) {
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

template<typename Iterator, typename ValueIterator>
Iterator FindAny(Iterator begin, Iterator end,
                 ValueIterator valueBegin, ValueIterator valueEnd)
{	
	return FindAny(begin, end, valueBegin, valueEnd, stx::Equals());
}

template<typename Iterator, typename ValueIterator, typename BinaryPredicate>
Iterator FindAny(Iterator begin, Iterator end,
                 ValueIterator valueBegin, ValueIterator valueEnd,
                 BinaryPredicate equals)
{
	while (begin != end) {
		auto valueIter = valueBegin;
		while (valueIter != valueEnd) {
			if (equals(*begin, *valueIter)) {
				return begin;
			}
			++valueIter;
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

template<typename Iterator, typename ValueIterator, typename BinaryPredicate>
Iterator FindSequence(Iterator begin, Iterator end,
                      ValueIterator seqBegin, ValueIterator seqEnd,
                      BinaryPredicate equals)
{
	while (begin != end) {
		auto srcIter = begin;
		
		auto seqIter = seqBegin;
		while (true) {
			if (seqIter == seqEnd) {
				return begin;
			} else if (srcIter == end) {
				return end;
			} else if (!equals(*srcIter, *seqIter)) {
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
Iterator FindLastSequence(Iterator begin, Iterator end,
                          ValueIterator seqBegin, ValueIterator seqEnd)
{
	return FindLastSequence(begin, end, seqBegin, seqEnd, stx::Equals());
}

template<typename Iterator, typename ValueIterator, typename BinaryPredicate>
Iterator FindLastSequence(Iterator begin, Iterator end,
                          ValueIterator seqBegin, ValueIterator seqEnd,
                          BinaryPredicate equals)
{
	if (seqBegin == seqEnd) {
		return end;
	}

	auto result = end;

	while (true) {
		auto current = FindSequence(begin, end, seqBegin, seqEnd, equals);

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

}/*end of stx namespace*/

#endif
