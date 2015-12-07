#ifndef STX_ALGORITHM_SORT_H
#define STX_ALGORITHM_SORT_H

#include <stx/Iterator.h>
#include <stx/utility/Compare.h>
#include <stx/algorithm/SwapPointee.h>

namespace stx {

template<typename Iterator, typename Compare>
Iterator FindSortedEnd(Iterator begin, Iterator end, Compare compare)
{
	if (begin == end) {
		return end;
	}

	auto next = begin;
	++next;
	while (next != end) {
		if (compare(*next, *begin)) {
			return next;
		}
		++next;
		++begin;
	}

	return end;
}

template<typename Iterator>
Iterator FindSortedEnd(Iterator begin, Iterator end)
{
	return stx::FindSortedEnd(begin, end, stx::Less());
}

template<typename Iterator, typename Compare>
bool IsSorted(Iterator begin, Iterator end, Compare compare)
{
	return stx::FindSortedEnd(begin, end, compare) == end;
}

template<typename Iterator>
bool IsSorted(Iterator begin, Iterator end)
{
	return stx::IsSorted(begin, end, stx::Less());
}

template<typename Iterator, typename Compare>
void Sort(Iterator begin, Iterator end, Compare compare)
{
	using std::advance;
	using std::distance;

	auto dist = distance(begin, end);
	if (dist < 2) {
		return;
	}
	
	auto mid = begin;
	advance(mid, dist / 2);
	stx::SwapPointee(begin, mid);

	auto b = begin;
	++b;
	auto e = end;
	--e;

	while (b != e) {
		while (b != e && compare(*b, *begin)) {
			++b;
		}
		while (b != e && !compare(*e, *begin)) {
			--e;
		}

		if (b != e) {
			stx::SwapPointee(b, e);
			++b;
			if (b == e) {
				break;
			}
			--e;
		}
	}
	if (compare(*b, *begin)) {
		++b;
	}

	stx::Sort(begin, b, compare);
	stx::Sort(b, end, compare);
}

template<typename Iterator>
void Sort(Iterator begin, Iterator end)
{
	stx::Sort(begin, end, stx::Less());
}

template<typename Iterator, typename Compare>
void PartialSort(Iterator begin, Iterator middle, Iterator end, Compare compare)
{
}

template<typename Iterator>
void PartialSort(Iterator begin, Iterator middle, Iterator end)
{
	stx::PartialSort(begin, end, stx::Less());
}

template<typename Iterator1, typename Iterator2, typename Compare>
Iterator2 CopyPartiallySorted(Iterator1 begin, Iterator1 end,
                              Iterator2 outBegin, Iterator2 outEnd,
                              Compare compare)
{
	return outBegin;
}

template<typename Iterator1, typename Iterator2>
Iterator2 CopyPartiallySorted(Iterator1 begin, Iterator1 end,
                              Iterator2 outBegin, Iterator2 outEnd)
{
	return stx::CopyPartiallySorted(begin, end, outBegin, outEnd,
	                                stx::Less());
}

template<typename Iterator, typename Compare>
void StableSort(Iterator begin, Iterator end, Compare compare)
{
}

template<typename Iterator>
void StableSort(Iterator begin, Iterator end)
{
	stx::StableSort(begin, end, stx::Less());
}

} /*end of stx namespace */

#endif

