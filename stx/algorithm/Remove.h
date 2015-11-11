#ifndef STX_ALGORITHM_REMOVE_H
#define STX_ALGORITHM_REMOVE_H

namespace stx {

template<typename Iterator, typename UnaryPredicate>
Iterator Remove(Iterator begin, Iterator end, UnaryPredicate check)
{
	while (begin != end && !check(*begin)) {
		++begin;
	}

	if (begin == end) {
		return end;
	}

	auto iter = begin;
	++begin;
	while (begin != end) {
		if (!check(*begin)) {
			*iter = *begin;
			++iter;
		}
		++begin;
	}

	return iter;
}

template<typename Iterator, typename T>
Iterator RemoveValue(Iterator begin, Iterator end, const T& value)
{
	while (begin != end && *begin != value) {
		++begin;
	}

	if (begin == end) {
		return end;
	}

	auto iter = begin;
	++begin;
	while (begin != end) {
		if (*begin != value) {
			*iter = *begin;
			++iter;
		}
		++begin;
	}

	return iter;
}

}

#endif

