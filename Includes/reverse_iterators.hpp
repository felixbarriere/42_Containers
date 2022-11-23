#pragma once

#include "iterators.hpp"

namespace ft
{
template <class _Iter>
class reverse_iterator : public ft::iterator<typename iterator_traits<_Iter>::iterator_category,
										typename iterator_traits<_Iter>::value_type,
										typename iterator_traits<_Iter>::difference_type,
										typename iterator_traits<_Iter>::pointer,
										typename iterator_traits<_Iter>::reference >
{
	private:
    _Iter __t; 
	protected:
    _Iter _current;
	public:
    typedef _Iter                                           			iterator_type;
    typedef typename ft::iterator_traits<_Iter>::difference_type 		difference_type;
    typedef typename ft::iterator_traits<_Iter>::reference       		reference;
    typedef typename ft::iterator_traits<_Iter>::pointer         		pointer;
	typedef typename ft::iterator_traits<_Iter>::iterator_category  	iterator_category;
    typedef typename ft::iterator_traits<_Iter>::value_type     	 	value_type;


    reverse_iterator() : __t(), _current() {}

    explicit
	reverse_iterator(_Iter it) : __t(it), _current(it) {}

    template <class Iter>
    reverse_iterator(const reverse_iterator<Iter>& rev_it) : __t(rev_it.base()), _current(rev_it.base()) {}

    template <class Iter>  // C++11
    reverse_iterator& 
	operator=(const reverse_iterator<Iter>& rev_it)
	{
        __t = _current = rev_it.base();
        return *this;
    }

    _Iter
	base() const {return _current;}
    
	reference
	operator*() const 
	{
		_Iter __tmp = _current;
		return *--__tmp;
	}
    
	pointer
	operator->() const {return &(operator*());}
    
	reverse_iterator&								// pre-increment version
	operator++() {--_current; return *this;}
    
	reverse_iterator    							// post-increment version
	operator++(int) {
		reverse_iterator __tmp(*this);
		--_current;
		return __tmp;
	}
    
	reverse_iterator&
	operator--() {++_current; return *this;}
    
	reverse_iterator
	operator--(int)
	{
		reverse_iterator __tmp(*this);
		++_current;
		return __tmp;
	}
    
	reverse_iterator
	operator+ (difference_type _n) const {return reverse_iterator(_current - _n);}
    
	reverse_iterator&
	operator+=(difference_type _n) {_current -= _n; return *this;}
    
	reverse_iterator
	operator- (difference_type _n) const {return reverse_iterator(_current + _n);}
    
	reverse_iterator&
	operator-=(difference_type _n) {_current += _n; return *this;}
    
	reference
	operator[](difference_type _n) const {return *(*this + _n);}
};

template <class _Iter1, class _Iter2>
bool
operator==(const reverse_iterator<_Iter1>& lhs, const reverse_iterator<_Iter2>& rhs)
{
    return lhs.base() == rhs.base();
}

template <class _Iter1, class _Iter2>
bool
operator<(const reverse_iterator<_Iter1>& lhs, const reverse_iterator<_Iter2>& rhs)
{
    return lhs.base() > rhs.base();
}

template <class _Iter1, class _Iter2>
bool
operator!=(const reverse_iterator<_Iter1>& lhs, const reverse_iterator<_Iter2>& rhs)
{
    return lhs.base() != rhs.base();
}

template <class _Iter1, class _Iter2>
bool
operator>(const reverse_iterator<_Iter1>& lhs, const reverse_iterator<_Iter2>& rhs)
{
    return lhs.base() < rhs.base();
}

template <class _Iter1, class _Iter2>
bool
operator>=(const reverse_iterator<_Iter1>& lhs, const reverse_iterator<_Iter2>& rhs)
{
    return lhs.base() <= rhs.base();
}

template <class _Iter1, class _Iter2>
bool
operator<=(const reverse_iterator<_Iter1>& lhs, const reverse_iterator<_Iter2>& rhs)
{
    return lhs.base() >= rhs.base();
}


template <class _Iter1, class _Iter2>
typename reverse_iterator<_Iter1>::difference_type
operator-(const reverse_iterator<_Iter1>& lhs, const reverse_iterator<_Iter2>& rhs)
{
    return rhs.base() - lhs.base();
}

template <class _Iter>
typename reverse_iterator<_Iter>::difference_type
operator+(typename reverse_iterator<_Iter>::difference_type _n, const reverse_iterator<_Iter>& lhs)
{
    return reverse_iterator<_Iter>(lhs.base() - _n);
}
};