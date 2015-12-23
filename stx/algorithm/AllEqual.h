#ifndef STX_ALGORITHM_ALLEQUAL_H
#define STX_ALGORITHM_ALLEQUAL_H

#include <utility>
#include <stx/utility/Equals.h>

namespace stx {

template<typename Iterator1, typename Iterator2, typename BinaryPredicate>
bool AllEqual(Iterator1 begin1, Iterator1 end1,
              Iterator2 begin2, Iterator2 end2,
	      BinaryPredicate&& equals)
{
	/*TODO: random access iterators should return immediately on size mismatch*/
	while (begin1 != end1 && begin2 != end2) {
		if (!std::forward<BinaryPredicate>(equals)(*begin1, *begin2)) {
			return false;
		}

		++begin1;
		++begin2;
	}

	return begin1 == end1 && begin2 == end2;
}

template<typename Iterator1, typename Iterator2>
bool AllEqual(Iterator1 begin1, Iterator1 end1,
              Iterator2 begin2, Iterator2 end2)
{
	return stx::AllEqual(begin1, end1, begin2, end2, stx::Equals());	
}

}

#endif
