#ifndef STX_ALGORITHM_INNERPRODUCT_H
#define STX_ALGORITHM_INNERPRODUCT_H

#include <utility>
#include <stx/utility/Arithmetic.h>

namespace stx {

template<typename Iterator1, typename Iterator2,
         typename T,
         typename BinarySum, typename BinaryProduct>
T InnerProduct(Iterator1 begin1, Iterator1 end1,
               Iterator2 begin2, Iterator2 end2,
               T&& initial,
               BinarySum sum, BinaryProduct product)
{
	T result(std::forward<T>(initial));
	while (begin1 != end1 && begin2 != end2) {
		result = sum(result, product(*begin1, *begin2));
		++begin1;
		++begin2;
	}

	return result;
}

template<typename Iterator1, typename Iterator2, typename T>
T InnerProduct(Iterator1 begin1, Iterator1 end1,
               Iterator2 begin2, Iterator2 end2,
               T&& initial)
{
	return stx::InnerProduct(begin1, end1, begin2, end2,
	                         std::forward<T>(initial),
	                         stx::Add(), stx::Multiply());
}

} /* end of stx namespace */

#endif
