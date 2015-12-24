#ifndef STX_ALGORITHM_INSERTIONSORT_H
#define STX_ALGORITHM_INSERTIONSORT_H

#include <stx/utility/Compare.h>
#include <stx/algorithm/Rotate.h>

namespace stx {

template<typename Iterator, typename Compare>
void InsertionSort(Iterator begin, Iterator end, Compare&& compare)
{
	if (begin == end) {
		return;
	}

	auto iter = begin;
	++iter;
	while (iter != end)
	{
		auto pos = iter;
		--pos;

		while (pos != begin)
		{
			if (std::forward<Compare>(compare)(*iter, *pos)) {
				--pos;
			} else {
				break;
			}
		}

		if (pos != begin || !std::forward<Compare>(compare)(*iter, *pos)) {
			++pos;
		}

		auto next = iter;
		++next;

		stx::Rotate(pos, iter, next);
		iter = next;
	}
}

template<typename Iterator>
void InsertionSort(Iterator begin, Iterator end)
{
	stx::InsertionSort(begin, end, stx::Less());
}

}/*end of stx namespace*/

#endif
