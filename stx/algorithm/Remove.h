#ifndef STX_ALGORITHM_REMOVE_H
#define STX_ALGORITHM_REMOVE_H

#include <stx/utility/Iterator.h>
#include <stx/utility/Equals.h>

namespace stx {

template<typename Iterator, typename UnaryPredicate>
Iterator Remove(Iterator begin, Iterator end, UnaryPredicate&& check)
{
	while (begin != end && !std::forward<UnaryPredicate>(check)(*begin)) {
		++begin;
	}

	if (begin == end) {
		return end;
	}

	auto iter = begin;
	++begin;
	while (begin != end) {
		if (!std::forward<UnaryPredicate>(check)(*begin)) {
			/*TODO: what about std::move*/
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
			/*TODO: what about std::move*/
			*iter = *begin;
			++iter;
		}
		++begin;
	}

	return iter;
}

template<typename Iterator>
Iterator RemoveDuplicates(Iterator begin, Iterator end)
{
	return RemoveDuplicates(begin, end, stx::Equals());
}

template<typename Iterator, typename BinaryPredicate>
Iterator RemoveDuplicates(Iterator begin, Iterator end,
                          BinaryPredicate&& equals)
{
	while (begin != end) {
		auto next = begin;
		++next;
		if (next == end) {
			break;
		}

		end = Remove(next, end, [&](auto& item) {
			return std::forward<BinaryPredicate>(equals)(*begin, item);
		});
		++begin;
	}

	return end;
}

template<typename Iterator>
Iterator RemoveConsecutiveDuplicates(Iterator begin, Iterator end)
{
	return RemoveConsecutiveDuplicates(begin, end, stx::Equals());
}

template<typename Iterator, typename BinaryPredicate>
Iterator RemoveConsecutiveDuplicates(Iterator begin, Iterator end,
                                     BinaryPredicate&& equals)
{
	if (begin == end) {
		return end;
	}

	auto iter = begin;
	while (true) {
		while (++begin != end
		    && std::forward<BinaryPredicate>(equals)(*iter, *begin)) {
		}

		++iter;

		if (begin == end) {
			break;
		} else {
			/*TODO: what about std::move*/
			*iter = *begin;
		}
	}

	return iter;
}

} /*end of stx namespace*/

#endif

