#ifndef STX_ALGORITHM_ROTATE_H
#define STX_ALGORITHM_ROTATE_H

#include <stx/algorithm/Reverse.h>

namespace stx {

template<typename Iterator>
void Rotate(Iterator begin, Iterator newBegin, Iterator end)
{
	stx::Reverse(begin, newBegin);
	stx::Reverse(newBegin, end);
	stx::Reverse(begin, end);
}

}

#endif
