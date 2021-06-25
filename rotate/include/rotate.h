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
   if(first == n_first) 
      return last;
   if(n_first == last) 
      return first;
 
   ForwardIt read, write, next_read; 
   read = n_first, write = first, next_read = first; 
 
   while(read != last){
      if(write == next_read) 
          next_read = read; 
          
      auto temp = *write;
      *write = *read;
      *read = temp;
      write++;
      read++;
   }
 
   rotate(write, next_read, last);

   return write;

}

}
#endif
