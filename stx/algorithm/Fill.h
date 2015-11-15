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

template<typename Iterator, typename Size, typename T>
Iterator FillN(Iterator begin, Size count, const T& value)
{
	/*TODO: tag dispatching*/
	Size i = 0;
	while (i < count) {
		*begin = value;
		++begin;
		++i;
	}

	return begin;
}

}

#endif

