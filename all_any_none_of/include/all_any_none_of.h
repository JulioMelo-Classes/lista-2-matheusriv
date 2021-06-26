#ifndef GRAAL_H
#define GRAAL_H

#include <utility>
using std::pair;
#include <iterator>
using std::distance;
#include <algorithm>
using std::sort;

namespace graal {

/*! 
 * TODO: documentação no estilo doxygen
 */
bool p( const int &a){
    return true;
}

template<class InputIt, class UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate p)
{
    if(first==last) return false;

    for(; first!=last; ++first){
        if(!p(*first)) 
            return false;
    }
    return true;
}

/*! 
 * TODO: documentação no estilo doxygen
 */
template<class InputIt, class UnaryPredicate>
bool any_of(InputIt first, InputIt last, UnaryPredicate p)
{
    for(; first!=last; ++first){
        if(p(*first)) 
            return true;
    }
    return false;
}

/*! 
 * TODO: documentação no estilo doxygen
 */
template<class InputIt, class UnaryPredicate>
bool none_of(InputIt first, InputIt last, UnaryPredicate p)
{
    for(; first!=last; ++first){
        if(p(*first)) 
            return false;
    }
    return true;
}

}
#endif
