#ifndef STX_ALGORITHM_ALL_H
#define STX_ALGORITHM_ALL_H

namespace stx {

template<typename Iterator, typename UnaryPredicate>
bool All(Iterator begin, Iterator end, UnaryPredicate check)
{
	while (begin != end) {
		if (!check(*begin)) {
			return false;
		}
		++begin;
	}

	return true;
}

}

#endif
