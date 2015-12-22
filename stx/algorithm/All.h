#ifndef STX_ALGORITHM_ALL_H
#define STX_ALGORITHM_ALL_H

#include <utility>

namespace stx {

template<typename Iterator, typename UnaryPredicate>
bool All(Iterator begin, Iterator end, UnaryPredicate&& check)
{
	while (begin != end) {
		if (!std::forward<UnaryPredicate>(check)(*begin)) {
			return false;
		}
		++begin;
	}

	return true;
}

}

#endif
