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
 * Exemplo de documentação seguindo o formato Doxygen
 *
 * @tparam Itr iterator para o range.
 * @tparam Compare o tipo de uma função bool(const T &a, const T &b)
 *
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range
 * @param cmp A função de comparação que retorna true quando o primeiro parâmetro é menor do que o segundo
 *
 * @return Um std::pair contendo o menor e maior elemento, nesta ordem
 *
 */

bool cmp( const int &a, const int &b){
    return a < b;
}

template <typename Itr, typename Compare >
std::pair<Itr, Itr> minmax( Itr first, Itr last, Compare cmp )
{
    int size=0, equal=0;
    auto max = first, min = first;
    auto minElem = *first, maxElem = *first;

    if(first == last || ++first == last)
        return { min, max };

    for(Itr i=first; i!=last; ++i){
        size++;
        if(cmp(*i,minElem)) minElem=*i;   
        if(!cmp(*i,maxElem)) maxElem=*i;  
        if(*i==*first) equal++;
    }

    if(size==equal){
        max = --last;
        return { first, max };
    }
    else{ 
        for(Itr i=first; i!=last; ++i){
            if(*i==maxElem){ 
                max = i;
            }
        }
        for(Itr i=first; i!=last; ++i){
            if(*i==minElem){ 
                min = i;
                break; 
            }
        }
    }

    return { min, max };

}

}
#endif
