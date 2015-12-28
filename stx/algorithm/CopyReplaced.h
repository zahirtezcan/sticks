#ifndef STX_ALGORITHM_COPYREPLACED_H
#define STX_ALGORITHM_COPYREPLACED_H

#include <utility>
#include <stx/utility/Equals.h>

namespace stx {

template<typename Iterator, typename OutputIterator, typename UnaryPredicate, typename T>
OutputIterator CopyReplaced(Iterator begin, Iterator end,
                            OutputIterator output,
                            UnaryPredicate&& check,
			    const T& newValue)
{
	while (begin != end) {
		if (std::forward<UnaryPredicate>(check)(*begin)) {
			*output = newValue;
		} else {
			*output = *begin;
		}
		++output;
		++begin;
	}

	return output;
}

}/*end of stx namespace*/

#endif

