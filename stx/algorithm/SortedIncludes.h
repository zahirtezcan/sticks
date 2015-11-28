#ifndef STX_ALGORITHM_SORTEDINCLUDES_H
#define STX_ALGORITHM_SORTEDINCLUDES_H

#include <stx/utility/Compare.h>

namespace stx {

template<typename Iterator1, typename Iterator2, typename Compare>
bool SortedIncludes(Iterator1 begin1, Iterator1 end1,
                    Iterator2 begin2, Iterator2 end2,
                    Compare compare)
{
	while (begin2 != end2) {
		/* using binary search will reduce asymptotic cost*/
		while (begin1 != end1 && compare(*begin1, *begin2)) {
			++begin1;
		}

		if (begin1 == end1) {
			return false;
		}

		if (compare(*begin2, *begin1)) {
			return false;
		}

		++begin2;
		++begin1;
	}

	return true;
}

template<typename Iterator1, typename Iterator2>
bool SortedIncludes(Iterator1 begin1, Iterator1 end1,
                    Iterator2 begin2, Iterator2 end2)
{
	return stx::SortedIncludes(begin1, end1, begin2, end2, stx::Less());
}

} /* end of stx namespace */

#endif
