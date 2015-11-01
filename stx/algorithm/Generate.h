#ifndef STX_ALGORITHM_GENERATE_H
#define STX_ALGORITHM_GENERATE_H

#include <stx/Iterator.h>

namespace stx {

template<typename Iterator, typename Generator>
void Generate(Iterator begin, Iterator end, Generator generate)
{
	while (begin != end) {
		*begin = generate();
		++begin;
	}
}

template<typename Iterator, typename IndexedGenerator>
void GenerateIndexed(Iterator begin, Iterator end, IndexedGenerator generate)
{
	//We can hold another iterator and check for distance to begin instead of index variable.
	//  But such strategy only works good for random iterators.
	//  Also to make this transparent this variable's type is iterator difference type
	//    Standard C++ library "count" method also uses difference instead of straight size_t
	//    http://en.cppreference.com/w/cpp/algorithm/count
	stx::IteratorDifference<Iterator> index = 0;
	
	while (begin != end) {
		*begin = generate(index);
		++begin;
		++index;
	}
}

}

#endif
