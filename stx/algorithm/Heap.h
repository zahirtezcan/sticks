#ifndef STX_ALGORITHM_HEAP_H
#define STX_ALGORITHM_HEAP_H

#include <stx/Iterator.h>
#include <stx/utility/Compare.h>
#include <stx/algorithm/SwapPointee.h>

namespace stx {
namespace detail {

template<typename Difference>
Difference HeapLeftChild(Difference d)
{
	return 2 * d + 1;
}

template<typename Difference>
Difference HeapRightChild(Difference d)
{
	return 2 * d + 2;
}

template<typename Difference>
Difference HeapParent(Difference d)
{
	return (d - 1) / 2;
}

template<typename Difference, typename Iterator, typename Compare>
void HeapSiftDown(Difference lastParentIndex,
                  Difference parentIndex, Iterator parent,
                  Compare compare)
{
	using std::advance;
	using std::distance;
	using stx::SwapPointee;
	
	while (parentIndex <= lastParentIndex) {
		auto leftChildIndex = HeapLeftChild(parentIndex);
		auto leftChild = parent;
		advance(leftChild, leftChildIndex - parentIndex);
	
		auto rightChildIndex = leftChildIndex + 1;
		auto rightChild = leftChild;
		++rightChild;

		if (compare(*parent, *leftChild)) {
			if (compare(*leftChild, *rightChild)) {
				SwapPointee(parent, rightChild);
				parentIndex = rightChildIndex;
				parent = rightChild;
			} else {
				SwapPointee(parent, leftChild);
				parentIndex = leftChildIndex;
				parent = leftChild;
			}
		} else {
			if (compare(*parent, *rightChild)) {
				SwapPointee(parent, rightChild);
				parentIndex = rightChildIndex;
				parent = rightChild;
			} else {
				break;
			}
		}
	}
}

} /* end of detail namespace */

template<typename Iterator, typename Compare>
Iterator FindHeapEnd(Iterator begin, Iterator end, Compare compare)
{
	if (begin == end) {
		return end;
	}

	auto parent = begin;
	auto child = parent;
	++child;

	while (child != end) {
		if (compare(*parent, *child)) { /*left child*/
			return child;
		}
		++child;

		if (child == end || compare(*parent, *child)) {/*right child*/
			return child;
		}
		++child;/*move to next parent's child*/
		++parent;
	}

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
void MakeHeap(Iterator begin, Iterator end, Compare compare)
{
	using std::distance;
	using std::advance;
	if (begin == end) {
		return;
	}
	
	--end;
	if (begin == end) {
		return;
	}
	auto lastIndex = distance(begin, end);
	auto lastParentIndex = detail::HeapParent(lastIndex);

	auto parent = begin;
	advance(parent, lastParentIndex);
	auto parentIndex = lastParentIndex;
	
	while (true) {
		detail::HeapSiftDown(lastParentIndex,
		                     parentIndex, parent,
				     compare);

		if (parent == begin) {
			break;
		}
		--parent;
		--parentIndex;
	}
}

template<typename Iterator>
void MakeHeap(Iterator begin, Iterator end)
{
	stx::MakeHeap(begin, end, stx::Less());
}

template<typename Iterator, typename Compare>
void PushHeap(Iterator begin, Iterator end, Compare compare)
{
	using std::distance;
	using std::advance;
	
	auto childDist = distance(begin, end);

	if (childDist < 2) {
		return;
	}

	--childDist;
	auto child = end;
	--child;

	do {
		auto parentDist = detail::HeapParent(childDist);
		auto parent = child;
		advance(parent, parentDist - childDist);

		if (compare(*parent, *child)) {
			stx::SwapPointee(parent, child);
			child = parent;
			childDist = parentDist;
		} else {
			break;
		}
	} while (child != begin);
}

template<typename Iterator>
void PushHeap(Iterator begin, Iterator end)
{
	stx::PushHeap(begin, end, stx::Less());
}

template<typename Iterator, typename Compare>
void PopHeap(Iterator begin, Iterator end, Compare compare)
{
	using std::distance;
	using std::advance;
	if (begin == end) {
		return;
	}
	
	--end;
	if (begin == end) {
		return;
	}
	stx::SwapPointee(begin, end);
	
	auto maxDist = distance(begin, end);
	if (maxDist == 1) {
		return;
	}

	auto lastParentIndex = detail::HeapParent(maxDist - 1);

	auto parent = begin;
	auto parentIndex = distance(begin, parent);
	while (parentIndex <= lastParentIndex) {	
		auto leftChildIndex = detail::HeapLeftChild(parentIndex);
		auto leftChild = parent;
		advance(leftChild, leftChildIndex - parentIndex);
		
		auto rightChild = leftChild;
		++rightChild;
		if (compare(*parent, *leftChild)) {
			if (rightChild != end && compare(*leftChild, *rightChild)) {
				stx::SwapPointee(parent, rightChild);
				parent = rightChild;
				parentIndex = leftChildIndex + 1;
			}
			else {
				stx::SwapPointee(parent, leftChild);
				parent = leftChild;
				parentIndex = leftChildIndex;
			}
		} else {
			if (rightChild != end && compare(*parent, *rightChild)) {
				stx::SwapPointee(parent, rightChild);
				parent = rightChild;
				parentIndex = leftChildIndex + 1;
			} else {
				return;
			}
		}
	}
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
