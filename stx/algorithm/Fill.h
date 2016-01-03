#ifndef STX_ALGORITHM_FILL_H
#define STX_ALGORITHM_FILL_H

namespace stx {

template<typename Iterator, typename T>
void Fill(Iterator begin, Iterator end, const T& value)
{
	/*TODO: tag dispatching*/
	while (begin != end) {
		*begin = value;
		++begin;
	}
}

} /* end of stx namespace */

#endif

