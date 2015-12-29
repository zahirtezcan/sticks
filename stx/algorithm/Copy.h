#ifndef STX_ALGORITHM_COPY_H
#define STX_ALGORITHM_COPY_H

#include <stx/utility/Equals.h>
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

template<typename Iterator, typename OutputIterator>
OutputIterator CopyRotated(Iterator begin, Iterator newBegin, Iterator end,
                           OutputIterator output)
{
	output = stx::Copy(newBegin, end, output);
	output = stx::Copy(begin, newBegin, output);

	return output;
}

}/*end of stx namespace*/

#endif

