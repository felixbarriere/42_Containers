#pragma once

/* Comparaison entre les ranges (<) */

namespace ft
{
    template <class inputIt1, class inputIt2>
    bool lexicographical_compare (inputIt1 first1, inputIt1 last1, inputIt2 first2, inputIt2 last2)
    {
         for (;first1 != last1 && first1 != last1; ++first1, ++first2)
        {
            if (*first1 < *first2)
                return true;
            else if (*first1 > *first2 || *first2 == *last2 )
                return false;
        }
        return ((first1 == last1) && first2 != last2);  // ?
    }

}