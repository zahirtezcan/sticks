#ifndef STX_ALGORITHM_INNERPRODUCT_H
#define STX_ALGORITHM_INNERPRODUCT_H

namespace stx {

struct Plus
{
	template<typename T, typename U>
	auto operator()(const T& t, const U& u)
	{
		return t + u;
	}
};

struct Multiply
{
	template<typename T, typename U>
	auto operator()(const T& t, const U& u)
	{
		return t * u;
	}
};

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
	return stx::InnerProduct(begin1, end1, begin2, end2, initial, stx::Plus(), stx::Multiply());
}

}

#endif
