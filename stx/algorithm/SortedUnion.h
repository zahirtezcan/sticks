#ifndef STX_ALGORITHM_SORTEDUNION_H
#define STX_ALGORITHM_SORTEDUNION_H

#include <utility>
#include <stx/utility/Compare.h>
#include <stx/algorithm/Copy.h>

namespace stx {

template<typename Iterator1, typename Iterator2,
         typename OutputIterator, typename Compare>
OutputIterator SortedUnion(Iterator1 begin1, Iterator1 end1,
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
			*output = *begin2;
			++output;
			++begin2;
		} else {
			*output = *begin1;
			++output;
			++begin1;
			++begin2;
		}
	}

	return begin2 == end2
	     ? stx::Copy(begin1, end1, output)
	     : stx::Copy(begin2, end2, output);
}

template<typename Iterator1, typename Iterator2, typename OutputIterator>
OutputIterator SortedUnion(Iterator1 begin1, Iterator1 end1,
                           Iterator2 begin2, Iterator2 end2,
                           OutputIterator output)
{
	return stx::SortedUnion(begin1, end1, begin2, end2,
	                        output, stx::Less());
}

} /* end of stx namespace */

#endif
