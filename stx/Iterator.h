#ifndef STX_ITERATOR_H
#define STX_ITERATOR_H

#include <iterator>

namespace stx {

template<typename Iterator>
IteratorValue=typename std::iterator_traits<Iterator>::value_type;

template<typename Iterator>
IteratorDifference=typename std::iterator_traits<Iterator>::difference_type;

template<typename Iterator>
IteratorReference=typename std::iterator_traits<Iterator>::reference;

template<typename Iterator>
IteratorPointer=typename std::iterator_traits<Iterator>::pointer;

template<typename Iterator>
IteratorCategory=typename std::iterator_traits<Iterator>::iterator_category;

}

#endif
