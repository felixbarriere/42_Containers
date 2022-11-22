template <class _Iter>
class reverse_iterator : public iterator<typename iterator_traits<_Iter>::iterator_category,
										typename iterator_traits<_Iter>::value_type,
										typename iterator_traits<_Iter>::difference_type,
										typename iterator_traits<_Iter>::pointer,
										typename iterator_traits<_Iter>::reference>
{
	private:
    _Iter __t; 
	protected:
    _Iter _current;
	public:
    typedef _Iter                                            iterator_type;
    typedef typename iterator_traits<_Iter>::difference_type difference_type;
    typedef typename iterator_traits<_Iter>::reference       reference;
    typedef typename iterator_traits<_Iter>::pointer         pointer;
    typedef _If<__is_cpp17_random_access_iterator<_Iter>::value,
        random_access_iterator_tag,
        typename iterator_traits<_Iter>::iterator_category>  iterator_category;
    typedef typename iterator_traits<_Iter>::value_type      value_type;


    reverse_iterator() : __t(), _current() {}
    explicit reverse_iterator(_Iter lhs) : __t(lhs), _current(lhs) {}
    template <class _Up, class = __enable_if_t<
        !is_same<_Up, _Iter>::value && is_convertible<_Up const&, _Iter>::value
    > >
    reverse_iterator(const reverse_iterator<_Up>& __u)
        : __t(__u.base()), _current(__u.base())
    { }
    template <class _Up, class = __enable_if_t<
        !is_same<_Up, _Iter>::value &&
        is_convertible<_Up const&, _Iter>::value &&
        is_assignable<_Iter&, _Up const&>::value
    > >
    reverse_iterator& operator=(const reverse_iterator<_Up>& __u) {
        __t = _current = __u.base();
        return *this;
    }

    _Iter base() const {return _current;}
    reference operator*() const {_Iter __tmp = _current; return *--__tmp;}
    pointer  operator->() const {return _VSTD::addressof(operator*());}
    reverse_iterator& operator++() {--_current; return *this;}
    reverse_iterator  operator++(int) {reverse_iterator __tmp(*this); --_current; return __tmp;}
    reverse_iterator& operator--() {++_current; return *this;}
    reverse_iterator  operator--(int) {reverse_iterator __tmp(*this); ++_current; return __tmp;}
    reverse_iterator  operator+ (difference_type __n) const {return reverse_iterator(_current - __n);}
    reverse_iterator& operator+=(difference_type __n) {_current -= __n; return *this;}
    reverse_iterator  operator- (difference_type __n) const {return reverse_iterator(_current + __n);}
    reverse_iterator& operator-=(difference_type __n) {_current += __n; return *this;}
    reference         operator[](difference_type __n) const {return *(*this + __n);}
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
typename reverse_iterator<_Iter>
operator+(typename reverse_iterator<_Iter>::difference_type __n, const reverse_iterator<_Iter>& lhs)
{
    return reverse_iterator<_Iter>(lhs.base() - __n);
}
