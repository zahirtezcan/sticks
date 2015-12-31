#ifndef STX_ALGORITHM_COPYIF_H
#define STX_ALGORITHM_COPYIF_H

#include <utility>

namespace stx {

template<typename Iterator, typename OutputIterator, typename UnaryPredicate>
OutputIterator CopyIf(Iterator begin, Iterator end,
                      OutputIterator output,
                      UnaryPredicate&& check)
{
	while (begin != end) {
		if (std::forward<UnaryPredicate>(check)(*begin)) {
			*output = *begin;
			++output;
		}
		++begin;
	}

	return output;
}

}/*end of stx namespace*/

#endif

