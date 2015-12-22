#ifndef STX_ALGORITHM_MERGE_H
#define STX_ALGORITHM_MERGE_H

#include <utility>
#include <stx/utility/Compare.h>
#include <stx/algorithm/Copy.h>

namespace stx {

template<typename Iterator1, typename Iterator2,
         typename OutputIterator, typename Compare>
OutputIterator Merge(Iterator1 begin1, Iterator1 end1,
                     Iterator2 begin2, Iterator2 end2,
                     OutputIterator output,
                     Compare&& compare)
{
	while (begin1 != end1 && begin2 != end2) {
		if (std::forward<Compare>(compare)(*begin2, *begin1)) {
			*output = *begin2;
			++begin2;
		} else {
			*output = *begin1;
			++begin1;
		}
		++output;
	}

	if (begin1 == end1) {
		return stx::Copy(begin2, end2, output);
	} else {
		return stx::Copy(begin1, end1, output);
	}
}

template<typename Iterator1, typename Iterator2, typename OutputIterator>
OutputIterator Merge(Iterator1 begin1, Iterator1 end1,
                     Iterator2 begin2, Iterator2 end2,
                     OutputIterator output)
{
	return stx::Merge(begin1, end1, begin2, end2, output, stx::Less());
}

} /* end of stx namespace */

#endif
