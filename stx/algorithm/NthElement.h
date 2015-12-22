#ifndef STX_ALGORITHM_NTHELEMENT_H
#define STX_ALGORITHM_NTHELEMENT_H

#include <stx/Iterator.h>
#include <stx/utility/Compare.h>
#include <stx/algorithm/SwapPointee.h>
#include <stx/algorithm/Partition.h>

namespace stx {

template<typename Iterator, typename Compare>
void NthElement(Iterator begin, Iterator nth, Iterator end,
                Compare&& compare)
{
	using std::distance;
	using std::advance;
	
	if (begin == end) {
		return;
	}

	auto n = distance(begin, nth);
	auto pbegin = begin;
	auto pend = end;

	while (pbegin != pend) {
		auto pdist = distance(pbegin, pend);
		if (pdist == 1) {
			break;
		}

		auto mid = pbegin;
		advance(mid, pdist / 2);
		stx::SwapPointee(pbegin, mid);

		auto iter = pbegin;
		++iter;
		auto ppoint = stx::Partition(iter, pend, [&](auto& x) {
			return std::forward<Compare>(compare)(x, *pbegin);
		});
		--ppoint;
		stx::SwapPointee(pbegin, ppoint);
	
		if (ppoint == nth) {
			break;
		}

		auto ppdist = distance(begin, ppoint);
		if (ppdist > n) {
			pend = ppoint;
		} else {
			pbegin = ppoint;
		}
	}
}

template<typename Iterator>
void NthElement(Iterator begin, Iterator nth, Iterator end)
{
	stx::NthElement(begin, nth, end, stx::Less());
}

} /* end of stx namespace */

#endif
