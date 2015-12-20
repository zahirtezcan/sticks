#ifndef STX_ALGORITHM_MOVE_H
#define STX_ALGORITHM_MOVE_H

#include <utility>

namespace stx {

template<typename Iterator, typename OutputIterator>
OutputIterator Move(Iterator begin, Iterator end, OutputIterator output)
{
	/*TODO: tag dispatching*/

	while (begin != end) {
		*output = std::move(*begin);
		++output;
		++begin;
	}

	return output;
}

template<typename Iterator, typename Size, typename OutputIterator>
OutputIterator MoveN(Iterator begin, Size count, OutputIterator output)
{
	/*TODO: tag dispatching*/
	Size index = 0;
	while (index < count) {
		*output = std::move(*begin);
		++output;
		++begin;
		++index;
	}

	return output;
}

template<typename Iterator, typename BidirectionalIterator>
BidirectionalIterator MoveBackward(Iterator begin, Iterator end,
                                   BidirectionalIterator outputEnd)
{
	while (begin != end) {
		--end;
		--outputEnd;
		*outputEnd = std::move(*end);
	}

	return outputEnd;
}

template<typename Iterator, typename OutputIterator, typename UnaryPredicate>
OutputIterator MoveIf(Iterator begin, Iterator end,
                      OutputIterator output,
                      UnaryPredicate&& check)
{
	while (begin != end) {
		if (std::forward<UnaryPredicate>(check)(*begin)) {
			*output = std::move(*begin);
			++output;
		}
		++begin;
	}

	return output;
}

template<typename Iterator, typename OutputIterator>
OutputIterator MoveRotated(Iterator begin, Iterator newBegin, Iterator end,
                           OutputIterator output)
{
	output = stx::Move(newBegin, end, output);
	output = stx::Move(begin, newBegin, output);

	return output;
}

template<typename Iterator, typename OutputIterator>
OutputIterator MoveReversed(Iterator begin, Iterator end,
                            OutputIterator output)
{
	while (begin != end) {
		--end;
		*output = std::move(*end);
		++output;
	}

	return output;
}

template<typename Iterator, typename OutputIterator, typename UnaryPredicate, typename T>
OutputIterator MoveReplaced(Iterator begin, Iterator end,
                            OutputIterator output,
                            UnaryPredicate&& check,
			    const T& newValue)
{
	while (begin != end) {
		if (std::forward<UnaryPredicate>(check)(*begin)) {
			*output = newValue;
		} else {
			*output = std::move(*begin);
		}
		++output;
		++begin;
	}

	return output;
}

}/*end of stx namespace*/

#endif

