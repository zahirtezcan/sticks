#ifndef STX_ALGORITHM_COPY_H
#define STX_ALGORITHM_COPY_H

namespace stx {

template<typename Iterator, typename OutputIterator>
OutputIterator Copy(Iterator begin, Iterator end, OutputIterator output)
{
	/*TODO: tag dispatching*/

	while (begin != end) {
		*output = *begin;
		++output;
		++begin;
	}

	return output;
}

}/*end of stx namespace*/

#endif

