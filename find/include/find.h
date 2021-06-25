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

bool eq( const int &a, const int &b){
    return(a == b);
}

template<class InputIt, class T, class Equal>
InputIt find(InputIt first, InputIt last, const T& value, Equal eq)
{
    while(first != last){
        if(eq(*first,value)) 
            return first;
        first++;
    }
    return last;
    
}

}
#endif
