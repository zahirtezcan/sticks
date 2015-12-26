#ifndef STX_ALGORITHM_TRANSFORM_H
#define STX_ALGORITHM_TRANSFORM_H

#include <stx/utility/Iterator.h>

namespace stx {

template<typename InputIterator, typename OutputIterator, typename UnaryFunction>
OutputIterator Transform(InputIterator begin, InputIterator end,
                         OutputIterator output,
                         UnaryFunction&& transform)
{
	while (begin != end) {
		*output = std::forward<UnaryFunction>(transform)(*begin);
		++begin;
		++output;
	}
	return output;
}

/* In STL there also is a transform with 2 input sequences, which are in turn transformed by a binary operation.
 * That method does not take an end for second iterator sequence, I think it should.
 * That method only returns iterated output iterator BUT not the second input iterator
 *     I could have implemented a method with an ending secondary sequence
 *     or return a pair of iterators both for second input sequence and output iterator
 *        But implementing a proper zip-iterator will be better
 *           proper: may be i can make sort possible with it
 */

/**/
template<typename InputIterator, typename OutputIterator, typename UnaryIndexedFunction>
OutputIterator TransformIndexed(InputIterator begin, InputIterator end,
                                OutputIterator output,
                                UnaryIndexedFunction&& transform)
{
	stx::IteratorDifference<InputIterator> index = 0;

	while (begin != end) {
		*output = std::forward<UnaryIndexedFunction>(transform)(*begin, index);
		++begin;
		++index;
		++output;
	}
	return output;
}

}

#endif
