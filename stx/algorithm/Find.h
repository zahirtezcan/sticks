#ifndef STX_ALGORITHM_FIND_H
#define STX_ALGORITHM_FIND_H

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
	while (begin != end) {
		auto valueIter = valueBegin;
		while (valueIter != valueEnd) {
			if (*begin == *valueIter) {
				return begin;
			}
			++valueIter;
		}

		++begin;
	}

	return end;
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
	while (begin != end) {
		auto srcIter = begin;
		
		auto seqIter = seqBegin;
		while (true) {
			if (seqIter == seqEnd) {
				return begin;
			} else if (srcIter == end) {
				return end;
			} else if (*srcIter != *seqIter) {
				break;
			}

			++seqIter;
			++srcIter;
		}

		++begin;
	}

	return end;
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

}

#endif

