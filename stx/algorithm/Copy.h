#ifndef STX_ALGORITHM_COPY_H
#define STX_ALGORITHM_COPY_H

#include <stx/algorithm/Find.h>
#include <stx/utility/Equals.h>

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

template<typename Iterator, typename OutputIterator, typename UnaryPredicate>
OutputIterator CopyIf(Iterator begin, Iterator end,
                      OutputIterator output,
                      UnaryPredicate check)
{
	while (begin != end) {
		if (check(*begin)) {
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

template<typename Iterator, typename OutputIterator>
OutputIterator CopyReversed(Iterator begin, Iterator end,
                            OutputIterator output)
{
	while (begin != end) {
		--end;
		*output = *end;
		++output;
	}

	return output;
}

template<typename Iterator, typename OutputIterator>
OutputIterator CopyDistinct(Iterator begin, Iterator end,
                            OutputIterator output)
{
	return CopyDistinct(begin, end, output, stx::Equals());
}

template<typename Iterator, typename OutputIterator, typename BinaryPredicate>
OutputIterator CopyDistinct(Iterator begin, Iterator end,
                            OutputIterator output,
			    BinaryPredicate equals)
{
	/*We need to have that output iterator be a forward iterator*/
	auto outputBegin = output;
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

template<typename Iterator, typename OutputIterator>
OutputIterator CopyDistinctConsecutively(Iterator begin, Iterator end,
                                         OutputIterator output)
{
	return CopyDistinctConsecutively(begin, end, output, stx::Equals());
}

template<typename Iterator, typename OutputIterator, typename BinaryPredicate>
OutputIterator CopyDistinctConsecutively(Iterator begin, Iterator end,
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

}/*end of stx namespace*/

#endif

