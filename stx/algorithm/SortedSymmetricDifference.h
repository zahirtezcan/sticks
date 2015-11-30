#ifndef STX_ALGORITHM_SORTEDSYMMETRICDIFFERENCE_H
#define STX_ALGORITHM_SORTEDSYMMETRICDIFFERENCE_H

#include <stx/utility/Compare.h>
#include <stx/algorithm/Copy.h>

namespace stx {

template<typename Iterator1, typename Iterator2,
         typename OutputIterator, typename Compare>
OutputIterator SortedSymmetricDifference(Iterator1 begin1, Iterator1 end1,
                                         Iterator2 begin2, Iterator2 end2,
                                         OutputIterator output,
                                         Compare compare)
{
	while (begin1 != end1 && begin2 != end2) {
		if (compare(*begin1, *begin2)) {
			*output = *begin1;
			++output;
			++begin1;
		} else if (compare(*begin2, *begin1)) {
			*output = *begin2;
			++output;
			++begin2;
		} else {
			++begin1;
			++begin2;
		}
	}

	return begin2 == end2
	     ? stx::Copy(begin1, end1, output)
	     : stx::Copy(begin2, end2, output);
}

template<typename Iterator1, typename Iterator2, typename OutputIterator>
OutputIterator SortedSymmetricDifference(Iterator1 begin1, Iterator1 end1,
                                         Iterator2 begin2, Iterator2 end2,
                                         OutputIterator output)
{
	return stx::SortedSymmetricDifference(begin1, end1, begin2, end2,
	                                      output, stx::Less());
} 

} /* end of stx namespace */

#endif
