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

template<typename Iterator, typename T>
stx::IteratorDifference<Iterator> CountValue(Iterator begin, Iterator end,
                                             const T& value)
{
	using ValueType = stx::IteratorValue<Iterator>;
	return Count(begin, end, [&] (const ValueType& iv) { return iv == value; });
}

}

#endif
