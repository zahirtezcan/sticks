#ifndef STX_ALGORITHM_FOREACH_H
#define STX_ALGORITHM_FOREACH_H

#include <stx/utility/Iterator.h>

namespace stx {

template<typename Iterator, typename UnaryAction>
UnaryAction ForEach(Iterator begin, Iterator end, UnaryAction action)
{
	while (begin != end) {
		action(*begin);
		++begin;
	}
	return action;
}

template<typename Iterator, typename IndexedAction>
IndexedAction For(Iterator begin, Iterator end, IndexedAction action)
{
	stx::IteratorDifference<Iterator> index = 0;

	while (begin != end) {
		action(*begin, index);
		++begin;
		++index;
	}
	return action;
}

}

#endif

