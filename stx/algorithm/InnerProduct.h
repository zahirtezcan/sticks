#ifndef STX_ALGORITHM_INNERPRODUCT_H
#define STX_ALGORITHM_INNERPRODUCT_H

#include <stx/utility/Arithmetic.h>

namespace stx {

template<typename Iterator1, typename Iterator2, typename T, typename BinarySum, typename BinaryProduct>
T InnerProduct(Iterator1 begin1, Iterator1 end1, Iterator2 begin2, Iterator2 end2, T initial, BinarySum sum, BinaryProduct product)
{
	while (begin1 != end1 && begin2 != end2) {
		initial = sum(initial, product(*begin1, *begin2));
		++begin1;
		++begin2;
	}

	return initial;
}

template<typename Iterator1, typename Iterator2, typename T>
T InnerProduct(Iterator1 begin1, Iterator1 end1, Iterator2 begin2, Iterator2 end2, T initial)
{
	return stx::InnerProduct(begin1, end1, begin2, end2, initial, stx::Add(), stx::Multiply());
}

}

#endif
