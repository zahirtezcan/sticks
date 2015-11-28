#ifndef STX_ALGORITHM_MERGE_H
#define STX_ALGORITHM_MERGE_H

#include <stx/utility/Compare.h>

namespace stx {

template<typename Iterator1, typename Iterator2,
         typename OutputIterator, typename Compare>
OutputIterator Merge(Iterator1 begin1, Iterator1 end1,
                     Iterator2 begin2, Iterator2 end2,
                     OutputIterator output,
                     Compare compare)
{
	while (begin1 != end1 && begin2 != end2) {
		if (compare(*begin2, *begin1)) {
			*output = *begin2;
			++begin2;
		} else {
			*output = *begin1;
			++begin1;
		}
		++output;
	}

	while (begin1 != end1) {
		*output = *begin1;
		++begin1;
		++output;
	}
	
	while (begin2 != end2) {
		*output = *begin2;
		++begin2;
		++output;
	}

	return output;
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
