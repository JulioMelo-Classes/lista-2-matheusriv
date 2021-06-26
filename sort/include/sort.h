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
bool cmp(const int &a, const int &b){
    return (a < b);
}

template<class ForwardIt, class Comparison>
void sort(ForwardIt first, ForwardIt last, Comparison cmp)
{
    for(; first != last; ++first){
        for(ForwardIt j = first+1; j != last; ++j){ 
            if(!cmp(*first,*j)){
                //swap
                std::swap(*first,*j);
            }
        }
    }

}

}
#endif
