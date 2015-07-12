#pragma once

#include <vector>
#include <algorithm>

namespace stx {

template<typename T, typename Comparer = std::less<T>>
class sorted_vector
{
public:
	using size_type = typename std::vector<T>::size_type;
	using value_type = typename std::vector<T>::value_type;
	using reference = typename std::vector<T>::reference;
	using const_reference = typename std::vector<T>::const_reference;
	using iterator = typename std::vector<T>::iterator;
	using const_iterator = typename std::vector<T>::const_iterator;

	sorted_vector()
	{ }

	template<typename Iterator>
	sorted_vector(Iterator first, Iterator last)
		:
		items(first, last)
	{ 
		std::sort(items.begin(), items.end(), Comparer());
	}

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

	const_reference operator[](const size_type& index) const
	{
		return items.at(index);
	}

	iterator insert(const T& item)
	{
		auto iter = std::upper_bound(begin(), end(), item, Comparer());
		return items.insert(iter, item);
	}

	bool try_erase(const T& item)
	{
		auto iter = find(item);

		if (iter != end())
		{
			items.erase(iter);
			return true;
		}
		
		return false;
	}

	const_iterator find(const T& item) const
	{
		auto iters = std::equal_range(begin(), end(), item, Comparer());

		if (iters.first != iters.second)
		{
			//if equal range returns a non-empty range then item already exists
			return items.first;
		}

		return end();
	}

	const_iterator search(const T& item) const
	{
		return std::lower_bound(begin(), end(), item, Comparer());
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
	std::vector<T> items;
};

}