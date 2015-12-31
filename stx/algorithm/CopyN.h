#ifndef STX_ALGORITHM_COPYN_H
#define STX_ALGORITHM_COPYN_H

namespace stx {

template<typename Iterator, typename Size, typename OutputIterator>
OutputIterator CopyN(Iterator begin, Size count, OutputIterator output)
{
	/*TODO: tag dispatching*/
	Size index = 0;
	while (index < count) {
		*output = *begin;
		++output;
		++begin;
		++index;
	}

	return output;
}

}/*end of stx namespace*/

#endif

