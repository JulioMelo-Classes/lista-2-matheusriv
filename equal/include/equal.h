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
template<class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, Equal eq)
{
    for(; first1 != last1; ++first1, ++first2)
        if(eq(*first1,*first2) == false) return false; //aqui vc poderia fazer if(!eq(*first,*first2))

    return true;
}

template<class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1,
           InputIt2 first2, InputIt2 last2,
           Equal eq )
{
    int size1=0, size2=0;
    for(InputIt1 i = first1; i != last1; ++i)
        size1++;
    for(InputIt1 i = first2; i != last2; ++i)
        size2++;

    if(size1 != size2)
        return false;
    else{ 
        for(; first2 != last2; ++first1, ++first2)
            if(eq(*first1,*first2) == false) return false;
    }
    return true;

}

}
#endif
