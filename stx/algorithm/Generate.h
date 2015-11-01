#ifndef STX_ALGORITHM_GENERATE_H
#define STX_ALGORITHM_GENERATE_H

namespace stx {

template<typename Iterator, typename Generator>
void Generate(Iterator begin, Iterator end, Generator generate)
{
	while (begin != end) {
		*begin = generate();
		++begin;
	}
}

}

#endif
