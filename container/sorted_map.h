#pragma once

#include "sorted_vector.h"

namespace stx {

template<typename First, typename Second, typename FirstComparer = std::less<First> >
struct CompareFirsts : std::binary_function< std::pair<First, Second>, std::pair<First, Second>, bool>
{
	result_type operator()(const first_argument_type& x, const second_argument_type& y) const
	{
		return compareFirsts(x.first, y.first);
	}

	FirstComparer compareFirsts;
};

template<typename Key, typename Value>
class sorted_map
{
	using Comparer = CompareFirsts < const Key, Value > ;
public:
	using value_type = typename std::pair<const Key, Value>;
	using iterator = typename std::vector<value_type>::iterator;
	using const_iterator = typename std::vector<value_type>::const_iterator;
	using size_type = typename std::vector<value_type>::size_type;
	using const_reference = typename std::vector<value_type>::const_reference;

	sorted_map()
	{ }

	void reserve(const size_type& count)
	{
		items.reserve(count);
	}

	void clear()
	{
		items.clear();
	}

	size_type count()
	{
		return items.size();
	}

	const_reference operator[](const Key& key) const
	{
		auto iter = find(item);

		if (iter != end())
		{
			return *iter;
		}

		throw std::runtime_error("Cannot find given key");
	}

	iterator try_insert(const Key& key, const Value& value)
	{
		value_type pair(key, value);

		auto iters = std::equal_range(begin(), end(), pair, Comparer());
		
		if (iters.first != iters.second)
		{
			//if equal range returns a non-empty range then item already exists
			return end();
		}

		return items.insert(iters.second, item);
	}

	bool try_erase(const Key& key)
	{
		auto iter = find(item);

		if (iter != end())
		{
			items.erase(iter);
			return true;
		}

		return false;
	}

	const_iterator find(const Key& key) const
	{
		value_type pair(key, Value());
		auto iters = std::equal_range(begin(), end(), pair, Comparer());

		if (iters.first != iters.second)
		{
			//if equal range returns a non-empty range then item already exists
			return items.first;
		}

		return end();
	}

	const_iterator search(const Key& key) const
	{
		value_type pair(key, Value());

		return std::lower_bound(items.begin(), items.end(), pair, Comparer());
	}

	iterator begin()
	{
		return items.begin();
	}

	iterator end()
	{
		return items.end();
	}

	const_iterator begin() const
	{
		return items.begin();
	}

	const_iterator end() const
	{
		return items.end();
	}
private:
	std::vector<value_type> items;
};


}