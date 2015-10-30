#ifndef STX_ALGORITHM_FINDPARTITIONPOINT_H
#define STX_ALGORITHM_FINDPARTITIONPOINT_H

#include <iterator>

namespace stx {

template<typename Iterator, typename UnaryPredicate>
Iterator FindPartitionPoint(Iterator begin, Iterator end, UnaryPredicate check)
{
	using std::distance;
	using std::advance;

	if (begin == end) return end;

	auto dist = distance(begin, end);
	auto mid = begin;
	advance(mid, dist / 2);

	if (check(*mid)) {
		advance(mid, 1);
		return FindPartitionPoint(mid, end, check);
	} else {
		return FindPartitionPoint(begin, mid, check);
	}
}

}

#endif

