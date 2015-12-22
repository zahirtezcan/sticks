#ifndef STX_ALGORITHM_MERGEINPLACE_H
#define STX_ALGORITHM_MERGEINPLACE_H

#include <stx/utility/Compare.h>
#include <stx/algorithm/Rotate.h>

namespace stx {

template<typename Iterator, typename Compare>
void MergeInplace(Iterator begin, Iterator middle, Iterator end,
                  Compare&& compare)
{
	if (begin == middle || middle == end) {
		return;
	}

	/*iterator for max-value in second part*/
	auto maxSecond = middle;
	/*iterator for min-value in first part*/
	auto minFirst = middle;
	--minFirst;

	while (minFirst != begin && maxSecond != end) {
		if (std::forward<Compare>(compare)(*maxSecond, *minFirst)) {
			--minFirst;
			++maxSecond;
		} else {
			break;
		}
	}

	if (maxSecond != end && minFirst == begin) {
		if (!std::forward<Compare>(compare)(*maxSecond, *minFirst)) {
			++minFirst;
		} else {
			++maxSecond;
		}
	} else {
		++minFirst;
	}

	stx::Rotate(minFirst, middle, maxSecond);
	
	stx::MergeInplace(begin, minFirst, middle, std::forward<Compare>(compare));
	stx::MergeInplace(middle, maxSecond, end, std::forward<Compare>(compare));
}

template<typename Iterator>
void MergeInplace(Iterator begin, Iterator middle, Iterator end)
{
	stx::MergeInplace(begin, middle, end, stx::Less());
}

}/* end of stx namespace */

#endif

