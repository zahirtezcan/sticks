#ifndef STX_ALGORITHM_HEAP_H
#define STX_ALGORITHM_HEAP_H

#include <utility>
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

template<typename Iterator, typename Difference, typename Compare>
void SiftDown(Iterator item, Difference itemIndex,
              Difference lastParentIndex,
	      Iterator end,
	      Compare&& compare)
{
	using std::advance;

	auto currentIndex = itemIndex;
	auto current = item;
	while (currentIndex <= lastParentIndex) {
		auto leftChildIndex = HeapLeftChild(currentIndex);
		auto leftChild = current;
		advance(leftChild, leftChildIndex - currentIndex);
	
		auto rightChildIndex = leftChildIndex + 1;
		auto rightChild = leftChild;
		++rightChild;

		if (std::forward<Compare>(compare)(*current, *leftChild)) {
			if (rightChild != end
			 && std::forward<Compare>(compare)(*leftChild, *rightChild)) {
				stx::SwapPointee(current, rightChild);
				currentIndex = rightChildIndex;
				current = rightChild;
			} else {
				stx::SwapPointee(current, leftChild);
				currentIndex = leftChildIndex;
				current = leftChild;
			}
		} else {
			if (rightChild != end
			 && std::forward<Compare>(compare)(*current, *rightChild)) {
				stx::SwapPointee(current, rightChild);
				currentIndex = rightChildIndex;
				current = rightChild;
			} else {
				break;
			}
		}
	}
}

} /* end of detail namespace */

template<typename Iterator, typename Compare>
Iterator FindHeapEnd(Iterator begin, Iterator end, Compare&& compare)
{
	if (begin == end) {
		return end;
	}

	auto parent = begin;
	auto child = parent;
	++child;

	while (child != end) {
		if (std::forward<Compare>(compare)(*parent, *child)) {
			/*left child*/
			return child;
		}
		++child;

		if (child == end
		 || std::forward<Compare>(compare)(*parent, *child)) {
			/*right child*/
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
bool IsHeap(Iterator begin, Iterator end, Compare&& compare)
{
	return stx::FindHeapEnd(begin, end, std::forward<Compare>(compare)) == end;
}

template<typename Iterator>
bool IsHeap(Iterator begin, Iterator end)
{
	return stx::IsHeap(begin, end, stx::Less());
}

template<typename Iterator, typename Compare>
void MakeHeap(Iterator begin, Iterator end, Compare&& compare)
{
	using std::distance;
	using std::advance;
	if (begin == end) {
		return;
	}
	
	auto length = distance(begin, end);
	if (length == 1) {
		return;
	}

	auto lastParentIndex = detail::HeapParent(length - 1);

	auto parent = begin;
	advance(parent, lastParentIndex);
	auto parentIndex = lastParentIndex;
	
	while (true) {
		detail::SiftDown(parent, parentIndex,
		                 lastParentIndex,
				 end,
				 std::forward<Compare>(compare));

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
void PushHeap(Iterator begin, Iterator end, Compare&& compare)
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

		if (std::forward<Compare>(compare)(*parent, *child)) {
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
void PopHeap(Iterator begin, Iterator end, Compare&& compare)
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
	detail::SiftDown(parent, parentIndex,
	                 lastParentIndex,
			 end,
			 std::forward<Compare>(compare));

	/* instead of inlining the sift operation we might have used a method
	 * but copying compare may be costly. We can use a reference to
	 * compare object as well but will that be a usual reference or
	 * are we allowed to use const reference etc.
	 *     Same thing applies for MakeHeap function template too.
	 */
}

template<typename Iterator>
void PopHeap(Iterator begin, Iterator end)
{
	stx::PopHeap(begin, end, stx::Less());
}

template<typename Iterator, typename Compare>
void SortHeap(Iterator begin, Iterator end, Compare&& compare)
{
	while (begin != end) {
		stx::PopHeap(begin, end, std::forward<Compare>(compare));
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
