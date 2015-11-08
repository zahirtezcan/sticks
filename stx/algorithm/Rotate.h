#ifndef STX_ALGORITHM_ROTATE_H
#define STX_ALGORITHM_ROTATE_H

#include <stx/algorithm/SwapPointee.h>

namespace stx {

template<typename Iterator>
Iterator Rotate(Iterator begin, Iterator newBegin, Iterator end)
{
	if (newBegin == end) {
		return end;
	}
	auto result = end;
	auto iter = newBegin;
	while (begin != newBegin) {
		stx::SwapPointee(begin, iter);
		++begin;
		++iter;
		if (iter == end) {
			iter = newBegin;
			if (result == end) {
				result = begin;
			}
		} else if (begin == newBegin) {
			newBegin = iter;
		} 

	}
	return result;
}

}

#endif
