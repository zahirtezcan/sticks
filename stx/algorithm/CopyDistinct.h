#ifndef STX_ALGORITHM_COPY_H
#define STX_ALGORITHM_COPY_H

#include <stx/algorithm/Find.h>
#include <stx/utility/Equals.h>
#include <utility>

namespace stx {

template<typename Iterator, typename OutputIterator, typename BinaryPredicate>
OutputIterator CopyDistinct(Iterator begin, Iterator end,
                            OutputIterator output,
			    BinaryPredicate&& equals)
{
	/*We need to have that output iterator be a forward iterator*/
	auto outputBegin = output;
	while (begin != end) {
		auto found = stx::Find(outputBegin, output, [&](auto& item) {
			return std::forward<BinaryPredicate>(equals)(*begin, item);
		});
	
		if (found == output) {
			*output = *begin;
			++output;
		}
		++begin;
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
OutputIterator CopyDistinctConsecutively(Iterator begin, Iterator end,
                                         OutputIterator output,
					 BinaryPredicate&& equals)
{
	if (begin == end) {
		return output;
	}
	while (begin != end) {
		*output = *begin;
		++output;

		auto iter = begin;
		while (++begin != end
		    && std::forward<BinaryPredicate>(equals)(*iter, *begin)) {
		}
	}

	return output;
}

template<typename Iterator, typename OutputIterator>
OutputIterator CopyDistinctConsecutively(Iterator begin, Iterator end,
                                         OutputIterator output)
{
	return CopyDistinctConsecutively(begin, end, output, stx::Equals());
}

}/*end of stx namespace*/

#endif

