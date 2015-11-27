#ifndef STX_ALGORITHM_ADJACENTDIFFERENCE_H
#define STX_ALGORITHM_ADJACENTDIFFERENCE_H

namespace stx {

struct Minus
{
	template<typename T, typename U>
	auto operator()(const T& t, const U& u) const
	{
		return t - u;
	}
};

template<typename Iterator, typename OutputIterator, typename BinaryDiff>
OutputIterator AdjacentDifference(Iterator begin, Iterator end,
                                  OutputIterator output,
                                  BinaryDiff diff)
{
	if (begin == end) {
		return output;
	}

	*output = *begin;
	++output;
	auto prev = begin;
	++begin;

	while (begin != end) {
		*output = diff(*begin, *prev);
		++begin;
		++prev;
		++output;
	}

	return output;
}

template<typename Iterator, typename OutputIterator>
OutputIterator AdjacentDifference(Iterator begin, Iterator end,
                                  OutputIterator output)
{
	return stx::AdjacentDifference(begin, end, output, stx::Minus());
}

}

#endif
