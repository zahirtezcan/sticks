#ifndef STX_ALGORITHM_COPYPARTITIONED_H
#define STX_ALGORITHM_COPYPARTITIONED_H

#include <utility>

namespace stx {

template<
	typename Iterator,
	typename OutputIterator1,
	typename OutputIterator2, 
	typename UnaryPredicate
	>
std::pair<OutputIterator1, OutputIterator2>
	CopyPartitioned(Iterator begin, Iterator end,
	                OutputIterator1 trueOutput,
			OutputIterator2 falseOutput,
	                UnaryPredicate&& check)
{
	while (begin != end) {
		if (std::forward<UnaryPredicate>(check)(*begin)) {
			*trueOutput = *begin;
			++trueOutput;
		} else {
			*falseOutput = *begin;
			++falseOutput;
		}
		++begin;
	}

	return { trueOutput, falseOutput };
}

}/*end of stx namespace*/

#endif

