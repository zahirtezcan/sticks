#ifndef STX_ALGORITHM_SORT_H
#define STX_ALGORITHM_SORT_H

#include <stx/Iterator.h>
#include <stx/utility/Compare.h>
#include <stx/algorithm/SwapPointee.h>
#include <stx/algorithm/Heap.h>

namespace stx {

template<typename Iterator, typename Compare>
Iterator FindSortedEnd(Iterator begin, Iterator end, Compare&& compare)
{
	if (begin == end) {
		return end;
	}

	auto next = begin;
	++next;
	while (next != end) {
		if (std::forward<Compare>(compare)(*next, *begin)) {
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
bool IsSorted(Iterator begin, Iterator end, Compare&& compare)
{
	return stx::FindSortedEnd(begin, end, std::forward<Compare>(compare)) == end;
}

template<typename Iterator>
bool IsSorted(Iterator begin, Iterator end)
{
	return stx::IsSorted(begin, end, stx::Less());
}

template<typename Iterator, typename Compare>
void Sort(Iterator begin, Iterator end, Compare&& compare)
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
		while (b != e && std::forward<Compare>(compare)(*b, *begin)) {
			++b;
		}
		while (b != e && !std::forward<Compare>(compare)(*e, *begin)) {
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

	if (std::forward<Compare>(compare)(*b, *begin)) {
		++b;
	}

	stx::Sort(begin, b, std::forward<Compare>(compare));
	stx::Sort(b, end, std::forward<Compare>(compare));
}

template<typename Iterator>
void Sort(Iterator begin, Iterator end)
{
	stx::Sort(begin, end, stx::Less());
}

template<typename Iterator, typename Compare>
void PartialSort(Iterator begin, Iterator middle, Iterator end, Compare&& compare)
{
	using std::distance;
	using std::advance;

	stx::MakeHeap(begin, middle, compare);
	auto heapDistance = distance(begin, middle);
	auto lastParentIndex = detail::HeapParent(heapDistance - 1);

	auto iter = middle;
	while (iter != end) {
		if (std::forward<Compare>(compare)(*iter, *begin)) {
			stx::SwapPointee(iter, begin);
			/*sift 'begin' down*/
			stx::IteratorDifference<Iterator> currentIndex = 0;
			Iterator current = begin;
			/* sift down current */
			while (currentIndex <= lastParentIndex) {
				auto leftChildIndex = detail::HeapLeftChild(currentIndex);
				auto leftChild = current;
				advance(leftChild, leftChildIndex - currentIndex);
			
				auto rightChildIndex = leftChildIndex + 1;
				auto rightChild = leftChild;
				++rightChild;

				if (std::forward<Compare>(compare)(*current, *leftChild)) {
					if (std::forward<Compare>(compare)(*leftChild, *rightChild)) {
						stx::SwapPointee(current, rightChild);
						currentIndex = rightChildIndex;
						current = rightChild;
					} else {
						stx::SwapPointee(current, leftChild);
						currentIndex = leftChildIndex;
						current = leftChild;
					}
				} else {
					if (std::forward<Compare>(compare)(*current, *rightChild)) {
						stx::SwapPointee(current, rightChild);
						currentIndex = rightChildIndex;
						current = rightChild;
					} else {
						break;
					}
				}
			}
		}
		++iter;
	}

	stx::SortHeap(begin, middle, compare);
}

template<typename Iterator>
void PartialSort(Iterator begin, Iterator middle, Iterator end)
{
	stx::PartialSort(begin, middle, end, stx::Less());
}

template<typename Iterator1, typename Iterator2, typename Compare>
Iterator2 CopyPartiallySorted(Iterator1 begin, Iterator1 end,
                              Iterator2 outBegin, Iterator2 outEnd,
                              Compare&& compare)
{
	using std::distance;
	using std::advance;
	/*TODO: tag dispatching for copy*/
	auto iter1 = begin;
	auto iter2 = outBegin;
	while (iter1 != end && iter2 != outEnd) {
		*iter2 = *iter1;
		++iter1;
		++iter2;
	}
	outEnd = iter2;

	stx::MakeHeap(outBegin, outEnd, compare);
	auto heapDistance = distance(outBegin, outEnd);
	auto lastParentIndex = detail::HeapParent(heapDistance - 1);

	while (iter1 != end) {
		if (std::forward<Compare>(compare)(*iter1, *outBegin)) {
			*outBegin = *iter1;
			/*sift 'outBegin' down*/
			stx::IteratorDifference<Iterator2> currentIndex = 0;
			Iterator2 current = outBegin;
			/* sift down current */
			while (currentIndex <= lastParentIndex) {
				auto leftChildIndex = detail::HeapLeftChild(currentIndex);
				auto leftChild = current;
				advance(leftChild, leftChildIndex - currentIndex);
			
				auto rightChildIndex = leftChildIndex + 1;
				auto rightChild = leftChild;
				++rightChild;

				if (std::forward<Compare>(compare)(*current, *leftChild)) {
					if (std::forward<Compare>(compare)(*leftChild, *rightChild)) {
						stx::SwapPointee(current, rightChild);
						currentIndex = rightChildIndex;
						current = rightChild;
					} else {
						stx::SwapPointee(current, leftChild);
						currentIndex = leftChildIndex;
						current = leftChild;
					}
				} else {
					if (std::forward<Compare>(compare)(*current, *rightChild)) {
						stx::SwapPointee(current, rightChild);
						currentIndex = rightChildIndex;
						current = rightChild;
					} else {
						break;
					}
				}
			}
		}
		++iter1;
	}

	stx::SortHeap(outBegin, outEnd, compare);
	return outEnd;
}

template<typename Iterator1, typename Iterator2>
Iterator2 CopyPartiallySorted(Iterator1 begin, Iterator1 end,
                              Iterator2 outBegin, Iterator2 outEnd)
{
	return stx::CopyPartiallySorted(begin, end, outBegin, outEnd,
	                                stx::Less());
}

template<typename Iterator, typename Compare>
void StableSort(Iterator begin, Iterator end, Compare&& compare)
{
}

template<typename Iterator>
void StableSort(Iterator begin, Iterator end)
{
	stx::StableSort(begin, end, stx::Less());
}

} /*end of stx namespace */

#endif

