#ifndef STX_ALGORITHM_FILLN_H
#define STX_ALGORITHM_FILLN_H

namespace stx {

template<typename Iterator, typename Size, typename T>
Iterator FillN(Iterator begin, Size count, const T& value)
{
	/*TODO: tag dispatching*/
	Size i = 0;
	while (i < count) {
		*begin = value;
		++begin;
		++i;
	}

	return begin;
}

} /* end of stx namespace */

#endif

