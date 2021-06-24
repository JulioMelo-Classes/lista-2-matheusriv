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
    auto max = first, min = first;

    if(first == last || ++first == last)
        return { min, max };

    if(cmp(*first, *min)) min = first;
    else max = first;

    for(Itr i = first; i != last; i++){
        auto a = first;
        if(++first == last){
            if(cmp(*a, *min)) 
                min = a;
            else if(!(cmp(*a, *max))) 
                max = a;
            break;
        }
        else{
            if(cmp(*first, *a)){
                if(cmp(*first, *min)) 
                    min = first;
                if(!(cmp(*a, *max))) 
                    max = a;
            } 
            else{
                if(cmp(*a, *min)) 
                    min = a;
                if(!(cmp(*first, *max))) 
                    max = first;
            }
        }
    }

    return { min, max };

}

}
#endif
