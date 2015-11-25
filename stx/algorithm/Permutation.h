#ifndef STX_ALGORITHM_PERMUTATION_H
#define STX_ALGORITHM_PERMUTATION_H

#include <stx/Iterator.h>
#include <stx/utility/Equals.h>
#include <stx/utility/Compare.h>
#include <stx/algorithm/Reverse.h>
#include <stx/algorithm/SwapPointee.h>

namespace stx {

template<typename Iterator, typename Compare>
bool NextPermutation(Iterator begin, Iterator end, Compare compare)
{
	if (begin == end) {
		return false;
	}

	auto prev = end;
	--prev;

	if (begin == prev) { /*single element*/
		return false;
	}

	auto next = prev;
	--prev;

	while (begin != next && !compare(*prev, *next)) {
		--prev;
		--next;
	}

	if (begin == next) {
		stx::Reverse(begin, end);
		return false;
	}

	auto iter = end;
	--iter;

	while (!compare(*prev, *iter)) {
		--iter;
	}

	stx::SwapPointee(prev, iter);
	stx::Reverse(next, end);

	return true;
}

template<typename Iterator>
bool NextPermutation(Iterator begin, Iterator end)
{
	return stx::NextPermutation(begin, end, stx::Less());
}

template<typename Iterator, typename Compare>
bool PreviousPermutation(Iterator begin, Iterator end, Compare compare)
{
	if (begin == end) {
		return false;
	}

	auto prev = end;
	--prev;

	if (begin == prev) { /*single element*/
		return false;
	}

	auto next = prev;
	--prev;

	while (begin != next && !compare(*next, *prev)) {
		--prev;
		--next;
	}

	if (begin == next) {
		stx::Reverse(begin, end);
		return false;
	}

	auto iter = end;
	--iter;

	while (!compare(*iter, *prev)) {
		--iter;
	}

	stx::SwapPointee(prev, iter);
	stx::Reverse(next, end);

	return true;
}

template<typename Iterator>
bool PreviousPermutation(Iterator begin, Iterator end)
{
	return stx::PreviousPermutation(begin, end, stx::Less());
}

template<typename Iterator1, typename Iterator2, typename BinaryPredicate>
bool IsPermutation(Iterator1 begin1, Iterator1 end1,
                   Iterator2 begin2, Iterator2 end2,
                   BinaryPredicate equals)
{
	return false;
}

template<typename Iterator1, typename Iterator2>
bool IsPermutation(Iterator1 begin1, Iterator1 end1,
                   Iterator2 begin2, Iterator2 end2)
{
	return stx::IsPermutation(begin1, end1, begin2, end2, stx::Equals());
}

}/* end of stx namespace */

#endif

