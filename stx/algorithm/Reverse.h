#ifndef STX_ALGORITHM_REVERSE_H
#define STX_ALGORITHM_REVERSE_H

#include <stx/algorithm/SwapPointee.h>

namespace stx {

template<typename Iterator>
void Reverse(Iterator begin, Iterator end)
{
	if (begin != end) {
		--end;
	}

	while (begin != end) {
		stx::SwapPointee(begin, end);
		++begin;
		if (begin != end) {
			--end;
		}
	}
}

}

#endif
