#ifndef STX_ALGORITHM_ITERSWAP_H
#define STX_ALGORITHM_ITERSWAP_H

#include <utility>

namespace stx {

template<typename Iterator1, typename Iterator2>
void IterSwap(Iterator1 iter1, Iterator2 iter2)
{
	using std::swap;
	swap(*iter1, *iter2);
}

}

#endif
