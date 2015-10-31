#ifndef STX_ITERATOR_H
#define STX_ITERATOR_H

#include <iterator>

namespace stx {

template<typename Iterator>
using IteratorValue=typename std::iterator_traits<Iterator>::value_type;

template<typename Iterator>
using IteratorDifference=typename std::iterator_traits<Iterator>::difference_type;

template<typename Iterator>
using IteratorReference=typename std::iterator_traits<Iterator>::reference;

template<typename Iterator>
using IteratorPointer=typename std::iterator_traits<Iterator>::pointer;

template<typename Iterator>
using IteratorCategory=typename std::iterator_traits<Iterator>::iterator_category;

}

#endif
