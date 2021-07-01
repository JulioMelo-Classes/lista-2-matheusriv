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
o problema aqui é que vários elementos do range podem ser repetidos em sequencia, assim vc não tem como fazer apenas um for
20%
*/
template<class InputIt, class Equal>
InputIt unique( InputIt first, InputIt last, Equal eq )
{
    if(first == last)
        return last;
 
    InputIt comp = first;
    for(; first != last; ++first){
        if(eq(*comp,*first)==false && ++comp != first)
            *(++comp) = *first;
    }

    return ++comp;
}

}
#endif
