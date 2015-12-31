#ifndef STX_ALGORITHM_SORTEDDIFFERENCE_H
#define STX_ALGORITHM_SORTEDDIFFERENCE_H

#include <utility>
#include <stx/utility/Compare.h>
#include <stx/algorithm/Copy.h>

namespace stx {

template<typename Iterator1, typename Iterator2,
         typename OutputIterator, typename Compare>
OutputIterator SortedDifference(Iterator1 begin1, Iterator1 end1,
                                Iterator2 begin2, Iterator2 end2,
                                OutputIterator output,
                                Compare&& compare)
{
	while (begin1 != end1 && begin2 != end2) {
		if (std::forward<Compare>(compare)(*begin1, *begin2)) {
			*output = *begin1;
			++output;
			++begin1;
		} else if (std::forward<Compare>(compare)(*begin2, *begin1)) {
			++begin2;
		} else {
			++begin1;
			++begin2;
		}
	}

	return stx::Copy(begin1, end1, output);
}

template<typename Iterator1, typename Iterator2, typename OutputIterator>
OutputIterator SortedDifference(Iterator1 begin1, Iterator1 end1,
                                Iterator2 begin2, Iterator2 end2,
                                OutputIterator output)
{
	return stx::SortedDifference(begin1, end1, begin2, end2,
	                             output, stx::Less());
}

} /* end of stx namespace */

#endif
