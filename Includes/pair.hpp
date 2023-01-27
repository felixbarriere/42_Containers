#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
  	template<class _T1, class _T2>
    struct pair
    {

	/* ****************************************************************************************** */
	/****************************************** CONSTRUCTORS **************************************/
		typedef _T1 first_type;
		typedef _T2 second_type;   

		_T1 first;              
		_T2 second;             

		pair() : first(), second() { }

		pair(const _T1& __a, const _T2& __b) : first(__a), second(__b) { }

		template<class _U1, class _U2>
		pair(const pair<_U1, _U2>& __p) : first(__p.first), second(__p.second) { }

		// no destructor on source code?

		/* ****************************************************************************************** */
		/**************************************** MEMBER OPERATORS ************************************/

		pair&
		operator=(const pair& __p)
		{ 
			first = __p.first;
			second = __p.second;
			return *this;
		}

		template<class _U1, class _U2>
		pair&
		operator=(const pair<_U1, _U2>& __p)
		{
			first = __p.first;
			second = __p.second;
			return *this;
		}
	};

	/* ****************************************************************************************** */
	/**************************************** NON-MEMBER OPERATORS ********************************/

	template<class _T1, class _T2>
	inline pair<_T1, _T2>
	make_pair(_T1 __x, _T2 __y) { return pair<_T1, _T2>(__x, __y); }

	/// Two pairs of the same type are equal iff their members are equal.
	template<class _T1, class _T2>
	inline bool
	operator==(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
	{ return __x.first == __y.first && __x.second == __y.second; }

	template<class _T1, class _T2>
	inline bool
	operator<(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
	{ return __x.first < __y.first
	  || (!(__y.first < __x.first) && __x.second < __y.second); }

	/// Uses operator== to find the result.
	template<class _T1, class _T2>
	inline bool
	operator!=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
	{ return !(__x == __y); }

	/// Uses operator< to find the result.
	template<class _T1, class _T2>
	inline bool
	operator>(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
	{ return __y < __x; }

	/// Uses operator< to find the result.
	template<class _T1, class _T2>
	inline bool
	operator<=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
	{ return !(__y < __x); }

	/// Uses operator< to find the result.
	template<class _T1, class _T2>
	inline bool
	operator>=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
	{ return !(__x < __y); }
 

	// template<class _T1, class _T2>
	// inline pair<_T1, _T2>
	// make_pair(_T1 __x, _T2 __y)
	// { return pair<_T1, _T2>(__x, __y); }

};

#endif
 
 