#ifndef STX_ALGORITHM_HEAP_H
#define STX_ALGORITHM_HEAP_H

#include <stx/utility/Compare.h>

namespace stx {

template<typename Iterator, typename Compare>
Iterator FindHeapEnd(Iterator /*begin*/, Iterator end, Compare /*compare*/)
{
	return end;
}

template<typename Iterator>
Iterator FindHeapEnd(Iterator begin, Iterator end)
{
	return stx::FindHeapEnd(begin, end, stx::Less());
}

template<typename Iterator, typename Compare>
bool IsHeap(Iterator begin, Iterator end, Compare compare)
{
	return stx::FindHeapEnd(begin, end, compare) == end;
}

template<typename Iterator>
bool IsHeap(Iterator begin, Iterator end)
{
	return stx::IsHeap(begin, end, stx::Less());
}

template<typename Iterator, typename Compare>
void MakeHeap(Iterator /*begin*/, Iterator /*end*/, Compare /*compare*/)
{
}

template<typename Iterator>
void MakeHeap(Iterator begin, Iterator end)
{
	stx::MakeHeap(begin, end, stx::Less());
}

template<typename Iterator, typename Compare>
void PushHeap(Iterator /*begin*/, Iterator /*end*/, Compare /*compare*/)
{
}

template<typename Iterator>
void PushHeap(Iterator begin, Iterator end)
{
	stx::PushHeap(begin, end, stx::Less());
}

template<typename Iterator, typename Compare>
void PopHeap(Iterator /*begin*/, Iterator /*end*/, Compare /*compare*/)
{
}

template<typename Iterator>
void PopHeap(Iterator begin, Iterator end)
{
	stx::PopHeap(begin, end, stx::Less());
}

template<typename Iterator, typename Compare>
void SortHeap(Iterator begin, Iterator end, Compare compare)
{
	while (begin != end) {
		stx::PopHeap(begin, end, compare);
		--end;
	}
}

template<typename Iterator>
void SortHeap(Iterator begin, Iterator end)
{
	stx::SortHeap(begin, end, stx::Less());
}

} /* end of stx namespace */

#endif
