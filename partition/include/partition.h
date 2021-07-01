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
 /*
 80%
 */
template<class ForwardIt, class UnaryPredicate>
ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    for(; first!=last; ++first){//realmente não entendi o que vc quer fazer com tantos laços... vc só precisava de 1, mas ok
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
