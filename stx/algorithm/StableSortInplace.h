#ifndef STX_ALGORITHM_STABLESORTINPLACE_H
#define STX_ALGORITHM_STABLESORTINPLACE_H

#include <stx/Iterator.h>
#include <stx/utility/Compare.h>
#include <stx/algorithm/InsertionSort.h>
#include <stx/algorithm/MergeInplace.h>

namespace stx {

template<typename Iterator, typename Compare>
void StableSortInplace(Iterator begin, Iterator end, Compare compare)
{
	using std::distance;
	using std::advance;

	auto length = distance(begin, end);

	if (length < 16) {
		stx::InsertionSort(begin, end, compare);
		return;
	}

	auto mid = begin;
	advance(mid, length / 2);

	stx::StableSortInplace(begin, mid, compare);
	stx::StableSortInplace(mid, end, compare);
	stx::MergeInplace(begin, mid, end, compare);
}

template<typename Iterator>
void StableSortInplace(Iterator begin, Iterator end)
{
	stx::StableSortInplace(begin, end, stx::Less());
}

} /* end of stx namespace */

#endif
