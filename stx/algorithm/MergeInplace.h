#ifndef STX_ALGORITHM_MERGEINPLACE_H
#define STX_ALGORITHM_MERGEINPLACE_H

#include <stx/utility/Compare.h>
#include <stx/algorithm/Rotate.h>

namespace stx {

template<typename Iterator, typename Compare>
void MergeInplace(Iterator begin, Iterator middle, Iterator end,
                  Compare compare)
{

	while (middle != end) {
		while (begin != middle && compare(*begin, *middle)) {
			++begin;
		}

		if (begin == middle) {
			break;
		}

		auto iter = middle;
		while (iter != end && compare(*iter, *begin)) {
			++iter;
		}

		stx::Rotate(begin, middle, iter);
		middle = iter;
	}
}

template<typename Iterator>
void MergeInplace(Iterator begin, Iterator middle, Iterator end)
{
	stx::MergeInplace(begin, middle, end, stx::Less());
}

}/* end of stx namespace */

#endif

