#ifndef STX_ALGORITHM_COPYREVERSED_H
#define STX_ALGORITHM_COPYREVERSED_H

namespace stx {

template<typename Iterator, typename OutputIterator>
OutputIterator CopyReversed(Iterator begin, Iterator end,
                            OutputIterator output)
{
	while (begin != end) {
		--end;
		*output = *end;
		++output;
	}

	return output;
}

}/*end of stx namespace*/

#endif

