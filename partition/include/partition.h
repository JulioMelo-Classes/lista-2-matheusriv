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
template<class ForwardIt, class UnaryPredicate>
ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    for(; first!=last; ++first){
        while(p(*first)){
            ++first;
            if(first==last) 
                return first;
        }
        do{
            --last;
            if(first==last) 
                return first;
        } while(!p(*last));
        std::swap(*first,*last);
    }
    return first;
}

}
#endif
