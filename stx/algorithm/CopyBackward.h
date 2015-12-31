#ifndef STX_ALGORITHM_COPYBACKWARD_H
#define STX_ALGORITHM_COPYBACKWARD_H

namespace stx {

template<typename Iterator, typename BidirectionalIterator>
BidirectionalIterator CopyBackward(Iterator begin, Iterator end,
                                   BidirectionalIterator outputEnd)
{
	while (begin != end) {
		--end;
		--outputEnd;
		*outputEnd = *end;
	}

	return outputEnd;
}

}/*end of stx namespace*/

#endif

