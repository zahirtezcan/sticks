#ifndef STX_ALGORITHM_ACCUMULATE_H
#define STX_ALGORITHM_ACCUMULATE_H

namespace stx {

template<typename Iterator, typename T>
T Accumulate(Iterator begin, Iterator end, T initial)
{
	while (begin != end) {
		initial += *begin;
		++begin;
	}

	return initial;
}

template<typename Iterator, typename T, typename BinaryFunction>
T Accumulate(Iterator begin, Iterator end, T initial, BinaryFunction f)
{
	while (begin != end) {
		initial = f(initial, *begin);
		++begin;
	}

	return initial;
}

}

#endif

