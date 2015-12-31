#ifndef STX_ALGORITHM_COPY_H
#define STX_ALGORITHM_COPY_H

#include <utility>

namespace stx {

template<typename Iterator, typename OutputIterator>
OutputIterator Copy(Iterator begin, Iterator end, OutputIterator output)
{
	/*TODO: tag dispatching*/

	while (begin != end) {
		*output = *begin;
		++output;
		++begin;
	}

	return output;
}

template<typename Iterator, typename Size, typename OutputIterator>
OutputIterator CopyN(Iterator begin, Size count, OutputIterator output)
{
	/*TODO: tag dispatching*/
	Size index = 0;
	while (index < count) {
		*output = *begin;
		++output;
		++begin;
		++index;
	}

	return output;
}

template<typename Iterator, typename BidirectionalIterator>
BidirectionalIterator CopyBackward(Iterator begin, Iterator end,
                                   BidirectionalIterator outputEnd)
{
	while (begin != end) {
		--end;
		--outputEnd;
		*outputEnd = *end;
	}

	return outputEnd;
}

}/*end of stx namespace*/

#endif

