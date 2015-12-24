#ifndef STX_ALGORITHM_ANY_H
#define STX_ALGORITHM_ANY_H

#include <utility>

namespace stx {

template<typename Iterator, typename UnaryPredicate>
bool Any(Iterator begin, Iterator end, UnaryPredicate&& check)
{
	while (begin != end) {
		if (std::forward<UnaryPredicate>(check)(*begin)) {
			return true;
		}
		++begin;
	}

	return false;
}

}

#endif
