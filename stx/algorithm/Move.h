#ifndef STX_ALGORITHM_MOVE_H
#define STX_ALGORITHM_MOVE_H

#include <utility>
/*#include <stx/algorithm/Find.h>
#include <stx/utility/Equals.h>*/

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
                      UnaryPredicate check)
{
	while (begin != end) {
		if (check(*begin)) {
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

template<typename Iterator, typename OutputIterator, typename UnaryPredicate>
OutputIterator MoveRemoved(Iterator begin, Iterator end,
                           OutputIterator output,
                           UnaryPredicate check)
{
	while (begin != end) {
		if (!check(*begin)) {
			*output = std::move(*begin);
			++output;
		}
		++begin;
	}

	return output;
}

template<typename Iterator, typename OutputIterator, typename UnaryPredicate, typename T>
OutputIterator MoveReplaced(Iterator begin, Iterator end,
                            OutputIterator output,
                            UnaryPredicate check,
			    const T& newValue)
{
	while (begin != end) {
		if (check(*begin)) {
			*output = newValue;
		} else {
			*output = std::move(*begin);
		}
		++output;
		++begin;
	}

	return output;
}

/*
template<typename Iterator, typename OutputIterator>
OutputIterator MoveDistinct(Iterator begin, Iterator end,
                            OutputIterator output)
{
	return MoveDistinct(begin, end, output, stx::Equals());
}

template<typename Iterator, typename OutputIterator, typename BinaryPredicate>
OutputIterator MoveDistinct(Iterator begin, Iterator end,
                            OutputIterator output,
			    BinaryPredicate equals)
{
*/	/*We need to have that output iterator be a forward iterator*/
/*	auto outputBegin = output;
	while (begin != end) {
		detail::EqualsPointee<Iterator, BinaryPredicate> eq(begin, equals);
		auto found = stx::Find(outputBegin, output, eq);
	
		if (found == output) {
			*output = *begin;
			++output;
		}
		++begin;
	}

	return output;
}
*/
/*
template<typename Iterator, typename OutputIterator>
OutputIterator MoveDistinctConsecutively(Iterator begin, Iterator end,
                                         OutputIterator output)
{
	return MoveDistinctConsecutively(begin, end, output, stx::Equals());
}

template<typename Iterator, typename OutputIterator, typename BinaryPredicate>
OutputIterator MoveDistinctConsecutively(Iterator begin, Iterator end,
                                         OutputIterator output,
					 BinaryPredicate equals)
{
	if (begin == end) {
		return output;
	}
	while (begin != end) {
		*output = *begin;
		++output;

		auto iter = begin;
		while (++begin != end && equals(*iter, *begin)) {
		}
	}

	return output;
}
*/

}/*end of stx namespace*/

#endif

