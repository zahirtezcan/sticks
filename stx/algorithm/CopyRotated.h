#ifndef STX_ALGORITHM_COPYROTATED_H
#define STX_ALGORITHM_COPYROTATED_H

#include <stx/algorithm/Copy.h>

namespace stx {

template<typename Iterator, typename OutputIterator>
OutputIterator CopyRotated(Iterator begin, Iterator newBegin, Iterator end,
                           OutputIterator output)
{
	output = stx::Copy(newBegin, end, output);
	output = stx::Copy(begin, newBegin, output);

	return output;
}

}/*end of stx namespace*/

#endif

