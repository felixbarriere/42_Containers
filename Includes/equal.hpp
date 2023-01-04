#pragma once

#include <algorithm>

/* Comparaison entre les éléments (first1/first2) et le début du range contenant first2 */

namespace ft
{
    template <class inputIt1, class inputIt2>
    bool
    equal (inputIt1 first1, inputIt1 last1, inputIt2 first2)
    {
        for (;first1 != last1; ++first1, ++first2)
        {
            if (*first1 != *first2)
                return false;
        }
        return true;
    }



}