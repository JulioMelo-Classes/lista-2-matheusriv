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
template<class ForwardIt>
ForwardIt rotate(ForwardIt first, ForwardIt n_first, ForwardIt last)
{
    ForwardIt next = n_first;
    while(first!=next){
        std::swap(*first,*next);
        first++, next++;
        if(next==last) 
            next = n_first;
        else if(first==n_first) 
            n_first = next;
    }
    
    return first;

}

}
#endif
