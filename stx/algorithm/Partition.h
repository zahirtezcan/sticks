#ifndef STX_ALGORITHM_FINDPARTITIONPOINT_H
#define STX_ALGORITHM_FINDPARTITIONPOINT_H

#include <iterator>
#include <stx/algorithm/SwapPointee.h>
#include <stx/algorithm/Rotate.h>

namespace stx {

template<typename Iterator, typename UnaryPredicate>
bool IsPartitioned(Iterator begin, Iterator end, UnaryPredicate check)
{
	while (begin != end && check(*begin)) {
		++begin;
	}
	
	/*we could have returned the partition point as result, instead of a boolean
	 *   but what would we have returned for false?
	 *      end iterator is not an answer because it is also a valid partition point
	 */
	/*auto partitionPoint = begin;*/

	if (begin == end) {
		/*if we don't early exit here, we will apply predicate twice for current*/
		return true;
	}
	++begin;
	while (begin != end) {
		if (check(*begin)) {
			return false;
		}
		++begin;
	}

	return true;
}

template<typename Iterator, typename UnaryPredicate>
Iterator Partition(Iterator begin, Iterator end, UnaryPredicate check)
{
	if (begin == end) {
		return end;
	}
	auto ppoint = begin;
	while (ppoint !=end && check(*ppoint)) {
		++ppoint;
	}
	if (ppoint == end) {
		return end;
	}
	begin = ppoint;

	while (true) {
		do {
			++begin;
		} while (begin != end && !check(*begin));
		if (begin == end) {
			return ppoint;
		}
		stx::SwapPointee(ppoint, begin);
		++ppoint;
	}
}

template<typename Iterator, typename UnaryPredicate>
Iterator StablePartition(Iterator begin, Iterator end, UnaryPredicate check)
{
	/* Using the algorithm from Sean Parent's CppCon2015 talk named
	 * "Better Code: Data Structures" (www.youtube.com/watch?v=sWgDk-o-6ZE)
	 */
	using std::distance;
	using std::advance;

	if (begin == end) {
		return end;
	}

	auto dist = distance(begin, end);

	if (dist == 1) {
		return check(*begin) ? end : begin;
	}

	auto mid = begin;
	advance(mid, dist / 2);

	auto part1 = stx::StablePartition(begin, mid, check);
	auto part2 = stx::StablePartition(mid, end, check);
	auto result = stx::Rotate(part1, mid, part2);
	
	return result;
}

template<typename Iterator, typename UnaryPredicate>
Iterator FindPartitionPoint(Iterator begin, Iterator end, UnaryPredicate check)
{
	using std::distance;
	using std::advance;

	while (begin != end) {
		auto dist = distance(begin, end);
		auto mid = begin;
		advance(mid, dist / 2);

		if (check(*mid)) {
			advance(mid, 1);
			begin = mid;
		} else {
			end = mid;
		}
	}

	return end;
}

}

#endif

