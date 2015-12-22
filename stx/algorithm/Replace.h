#ifndef STX_ALGORITHM_REPLACE_H
#define STX_ALGORITHM_REPLACE_H

#include <utility>

namespace stx {

template<typename Iterator, typename UnaryPredicate, typename U>
void Replace(Iterator begin, Iterator end,
             UnaryPredicate&& check,
	     const U& newValue)
{
	while (begin != end) {
		if (std::forward<UnaryPredicate>(check)(*begin)) {
			*begin = newValue;
		}
		++begin;
	}
}

template<typename Iterator, typename T, typename U>
void ReplaceValue(Iterator begin, Iterator end,
                  const T& oldValue,
		  const U& newValue)
{
	while (begin != end) {
		if (*begin == oldValue) {
			*begin = newValue;
		}
		++begin;
	}
}

}

#endif

