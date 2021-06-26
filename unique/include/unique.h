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
bool eq(const int &a, const int &b){
    if( a == b )  
        return true;
    else
        return false;
}

template<class InputIt, class Equal>
InputIt unique( InputIt first, InputIt last, Equal eq )
{
    if(first == last)
        return last;
 
    InputIt comp = first;
    while(first != last){
        if(eq(*comp,*first)==false && ++comp != first)
            *(++comp) = *first;
        ++first;
    }

    return ++comp;
}

}
#endif
