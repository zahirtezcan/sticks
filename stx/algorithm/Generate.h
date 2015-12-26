#ifndef STX_ALGORITHM_GENERATE_H
#define STX_ALGORITHM_GENERATE_H

#include <stx/utility/Iterator.h>

namespace stx {

template<typename Iterator, typename Generator>
void Generate(Iterator begin, Iterator end, Generator&& generate)
{
	while (begin != end) {
		*begin = std::forward<Generator>(generate)();
		++begin;
	}
}

template<typename Iterator, typename IndexedGenerator>
void GenerateIndexed(Iterator begin, Iterator end, IndexedGenerator&& generate)
{
	//We can hold another iterator and check for distance to begin instead of index variable.
	//  But such strategy only works good for random iterators.
	//  So to make it transparent this variable's type is iterator difference type
	//    Standard C++ library "count" method also uses difference instead of straight size_t
	//    http://en.cppreference.com/w/cpp/algorithm/count
	//Assume that this difference type can be initialized with zero
	stx::IteratorDifference<Iterator> index = 0;
	
	while (begin != end) {
		*begin = std::forward<IndexedGenerator>(generate)(index);
		++begin;
		++index;
	}
}

template<typename Iterator, typename T>
/* A rename for std::iota */
T GenerateIncrement(Iterator begin, Iterator end, T value)
{
	//This algorithm can easily be implemented via 'Generate'
	//  But I don't want to deal with ++value, value++ performance debate
	//  Similar applies for 'GenerateIndexed' method
	while (begin != end) {
		*begin = value;
		++begin;
		++value;
	}

	//std::iota returns void, but this may be useful
	return value;
}

}

#endif
