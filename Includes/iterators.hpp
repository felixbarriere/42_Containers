#pragma once   // directive de préprocesseur: le fichier source actuel est inclu une seule fois dans une seule compilation.

// # include <iostream>
# include <cstddef>
# include <memory>

# include "enable_if.hpp"
# include "is_integral.hpp"



namespace ft
{

	struct random_access_iterator_tag {} ;

	/**
	*	Traits class for iterators.
	* 	This class does nothing but defines nested typedefs. 
	*/

	template<typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
						typename _Pointer = _Tp*, typename _Reference = _Tp&>
	struct iterator
	{
		typedef _Category  iterator_category;
		typedef _Tp        value_type;
		typedef _Distance  difference_type;
		typedef _Pointer   pointer;
		typedef _Reference reference;
	};

	template<typename _Iterator>
	struct iterator_traits
	{
		typedef typename _Iterator::iterator_category iterator_category;
		typedef typename _Iterator::value_type        value_type;
		typedef typename _Iterator::difference_type   difference_type;
		typedef typename _Iterator::pointer           pointer;
		typedef typename _Iterator::reference         reference;
	};

	// Partial specialization for pointer types.
	template<typename _Tp>
	struct iterator_traits<_Tp*>
	{
		typedef random_access_iterator_tag  iterator_category;
		typedef _Tp                         value_type;
		typedef ptrdiff_t                   difference_type;
		typedef _Tp*                        pointer;
		typedef _Tp&                        reference;
	};

	// Partial specialization for const pointer types.
	template<typename _Tp>
	struct iterator_traits<const _Tp*>
	{
		typedef random_access_iterator_tag iterator_category;
		typedef _Tp                         value_type;
		typedef ptrdiff_t                   difference_type;
		typedef const _Tp*                  pointer;
		typedef const _Tp&                  reference;
	};
};
