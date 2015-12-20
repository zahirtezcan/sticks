#ifndef STX_ALGORITHM_LEXICOGRAPHICALCOMPARE_H
#define STX_ALGORITHM_LEXICOGRAPHICALCOMPARE_H

#include <stx/utility/Compare.h>
#include <utility>

namespace stx {

template<typename Iterator1, typename Iterator2, typename Compare>
bool LexicographicalCompare(Iterator1 begin1, Iterator1 end1,
                            Iterator2 begin2, Iterator2 end2,
                            Compare&& compare)
{
	while (begin1 != end1 && begin2 != end2) {
		if (std::forward<Compare>(compare)(*begin1, *begin2)) {
			return true;
		}
		if (std::forward<Compare>(compare)(*begin2, *begin1)) {
			return false;
		}
		++begin1;
		++begin2;
	}

	return begin1 == end1 && begin2 != end2;
	/* if  begin2 also equals to end2 then two sequences are equal.
	 * ergo return false
	 *   C++ std algorithms uses "compare" term in place of "less"
	 */
}

template<typename Iterator1, typename Iterator2>
bool LexicographicalCompare(Iterator1 begin1, Iterator1 end1,
                            Iterator2 begin2, Iterator2 end2)
{
	return stx::LexicographicalCompare(begin1, end1,
	                                   begin2, end2,
	                                   stx::Less());
}

template<typename CompareElement = stx::Less>
struct LexicographicallyLess
{
	template<typename Range1, typename Range2>
	bool operator()(const Range1& r1, const Range2& r2) const
	{
		using std::begin;
		using std::end;

		return stx::LexicographicalCompare(begin(r1), end(r1),
		                                   begin(r2), end(r2),
						   CompareElement());
	}
};

}/*end of stx namespace*/

#endif

