#ifndef STX_ALGORITHM_PARTIALSUM_H
#define STX_ALGORITHM_PARTIALSUM_H

#include <utility>
#include <stx/Iterator.h>
#include <stx/utility/Arithmetic.h>

namespace stx {

template<typename Iterator, typename OutputIterator, typename BinaryAdd>
OutputIterator PartialSum(Iterator begin, Iterator end,
                          OutputIterator output,
                          BinaryAdd&& add)
{
	if (begin == end) {
		return output;
	}

	stx::IteratorValue<Iterator> sum = *begin;
	output = sum;
	++begin;
	++output;

	while (begin != end) {
		sum = std::forward<BinaryAdd>(add)(sum, *begin);
		*output = sum;

		++begin;
		++output;
	}

	return output;
}

template<typename Iterator, typename OutputIterator>
OutputIterator PartialSum(Iterator begin, Iterator end,
                          OutputIterator output)
{
	return stx::PartialSum(begin, end, output, stx::Add());
}

} /* end of stx namespace */

#endif
