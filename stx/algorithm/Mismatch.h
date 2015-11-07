#ifndef STX_ALGORITHM_MISMATCH_H
#define STX_ALGORITHM_MISMATCH_H

#include <utility>

namespace stx {

template<typename Iterator1, typename Iterator2>
std::pair<Iterator1, Iterator2> Mismatch(Iterator1 begin1, Iterator1 end1,
                                         Iterator2 begin2, Iterator2 end2)
{
	while (begin1 != end1 && begin2 != end2 && *begin1 == *begin2) {
		++begin1;
		++begin2;
	}

	return { begin1, begin2 };
}

template<typename Iterator1, typename Iterator2, typename BinaryPredicate>
std::pair<Iterator1, Iterator2> Mismatch(Iterator1 begin1, Iterator1 end1,
                                         Iterator2 begin2, Iterator2 end2,
                                         BinaryPredicate equals)
{
	while (begin1 != end1 && begin2 != end2 && equals(*begin1, *begin2)) {
		++begin1;
		++begin2;
	}

	return { begin1, begin2 };
}

}

#endif
