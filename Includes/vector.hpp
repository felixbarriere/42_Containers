// #pragma once

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <iterator>
// # include <stdexcept>

# include "iterators.hpp"
# include "reverse_iterators.hpp"
# include "equal.hpp"
# include "lexicographical_compare.hpp"
# include "enable_if.hpp"
# include "equal.hpp"

// std::is_integral<int>::value;

namespace ft
{
	template < typename T, typename Alloc = std::allocator<T> >
	class vector
	{
	public:
		/* ****************************************************************************************** */
		/****************************************** ALIASES *******************************************/

		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef T*											iterator;
		typedef const T*									const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		/* ****************************************************************************************** */
		/************************************** MEMBER FUNCTIONS **************************************/
		
		/***************** Constructors / Destructor *****************/

		/* default constructor */
		explicit
		vector(const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _allocator(alloc), _begin(NULL) //, _end(NULL)
		{
			// std::cout << "DEFAULT CONSTRUCTOR" << std::endl;


		}

		/* fill constructor */
		explicit
		vector(size_type n, const T& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _allocator(alloc),
																							_begin(_allocator.allocate(n, 0)) //, _end(_begin + n) 
		{
			for (size_t i = 0; i < n ; i++)
				_allocator.construct(_begin + i, val);
		}

		/* range constructor */
		template <class InputIterator>
		vector( InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type())
													: _size(std::distance(first, last)), _capacity(std::distance(first, last)), _allocator(alloc),
													_begin(_allocator.allocate(std::distance(first, last), 0)) //, _end(first + std::distance(first, last))
		{
			for (size_t i = 0; first != last; i++, first++)
				_allocator.construct(_begin + i, *(first));
		}

		/* copy constructor */
		vector(const vector& cpy)
		{
			this->_size = cpy._size;
			this->_capacity = cpy._size;
			this->_allocator = cpy._allocator;
			this->_begin = _allocator.allocate(this->_capacity, 0);

			for (size_t i = 0; i < _size; i++)
				_allocator.construct(this->_begin + i, *(cpy._begin + i));
		}

		~vector()
		{
			if (_capacity != 0)
			{
				for (size_t i = 0; i < _size; i++)
					_allocator.destroy(_begin + i);
				_allocator.deallocate(_begin, _capacity);
			}		
		}

		vector&	operator=(const vector& assign)
		{
			if (this == &assign)
				return (*this);
			
			if (this->_capacity)
				for (size_t i = 0; i < _size; i++)
					this->_allocator.destroy(this->_begin + i);
			this->_allocator.deallocate(_begin, _capacity);
			
			if (this->_capacity < assign._size)
			{
				// this->_capacity = assign._capacity;
				this->_capacity = assign._size;
			}
			// this->_allocator = assign._allocator;
			this->_size = assign._size;
			this->_begin = _allocator.allocate(this->_capacity, 0);
			
			for (size_t i = 0; i < _size; i++)
					_allocator.construct(this->_begin + i, *(assign._begin + i));
			return (*this);	
		}

		/***************** Iterators *****************/

		iterator
		begin() { return (this->_begin); }
		
		const_iterator
		begin() const { return (this->_begin); }

		iterator
		end() { return (this->_begin + this->_size); }

		const_iterator
		end() const { return (this->_begin + this->_size); }

		reverse_iterator
		rbegin() { return (reverse_iterator(this->_begin + this->_size)); }

		reverse_iterator
		rend() { return (reverse_iterator(this->_begin)); }

		const_reverse_iterator
		rbegin() const { return (reverse_iterator(this->_begin + this->_size)); }

		const_reverse_iterator
		rend() const { return (reverse_iterator(this->_begin)); }

		/***************** Capacity *****************/

		size_type
		size() const { return (this->_size); }
		
		size_type
		max_size() const { return (this->_allocator.max_size()); }  // maximum potential size the container can reach due to known system
		
		void
		resize(size_type n, value_type val = value_type())     // Resizes the container so that it contains n elements. "val" is optional
		{
			if (n < this->size()) 
			{
				// Supprimer les éléments en trop
				iterator it = this->begin() + n;
				this->erase(it, this->end());
				// (*this).erase(begin() + n, end());
    		}
			else
			{
				if (n > this->_capacity)
				{
					if (this->_capacity * 2 > n)
					{
						reserve(this->_capacity * 2);
					}
					else
					{
						reserve (n);
					}
				}
				// Ajouter des éléments en fin de container
				for (; this->_size < n; this->_size++) 
					this->_allocator.construct((this->_begin + this->_size), val);
				this->_size = n;
      		}
		}

		size_type
		capacity() const { return (this->_capacity); }            // Return size of allocated storage capacity
		
		bool
		empty() const
		{
			if (this->_size == 0)
				return 1;
			else
				return 0;
		}

		void		reserve(size_type n)           // Requests that the vector capacity be at least enough to contain n elements.
		{
			if (n < this->_capacity)
				return ;
			else if (n > this->_allocator.max_size())
				throw std::length_error("vector::reserve");
			
			pointer	temp = _allocator.allocate(n);
			for (size_t i = 0; i < _size; i++)
					_allocator.construct(temp + i, *(_begin + i));
			
			if (_capacity != 0)
			{
				for (size_t i = 0; i < _size; i++)
					_allocator.destroy(_begin + i);
			}
			_allocator.deallocate(_begin, _capacity);
			this->_begin = temp;
			this->_capacity = n;
		}

		/***************** Element access *****************/

		value_type&		// 
		operator[](size_type n)	{ return (*(this->_begin + n)); }	 // should never call this function with an argument n that is out of range ==> undefined behavior.

		const value_type& // const T&
		operator[](size_type n) const { return (*(this->_begin + n)); }

		T&
		at(size_type n)
		{
			if (n < this->_size)
				return (*(this->_begin + n));
			else
				throw std::out_of_range("vector::at\n");
		}
		
		const T&
		at(size_type n) const
		{
			if (n < this->_size)
				return (*(this->_begin + n));
			else
				throw std::out_of_range("vector::at\n");
		}

		T&
		front()	{ return (*(this->_begin)); }				 // Unlike member vector::begin, which returns an iterator to this same element, this function returns a direct reference.
		
		const T&
		front() const { return (*(this->_begin)); }

		T&
		back() { return (*(this->_begin + (this->_size - 1))); }

		const T&
		back() const { return (*(this->_begin + (this->_size - 1))); }

		/***************** Modifiers *****************/

		template <class InputIterator>
		void
		assign(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)	// Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
		{
			size_t distance = std::distance(first, last);
			this->clear();
			reserve(distance);
			for (size_t i = 0; first != last; first++, i++)
				this->_allocator.construct(this->_begin + i, *first);
			this->_size = distance;
		}
		
		void
		assign(size_type n, const T& val)			// In the fill version (2), the new contents are n elements, each initialized to a copy of val.
		{
			// this->clear();
			// for (size_t i = 0; i < n; i++)
			// 	this->push_back(val);

			reserve(n);
			if (this->_capacity)
			for (size_t i = 0; i < this->_size; i++)
				this->_allocator.destroy(_begin + i);
			for(size_t i = 0; i < n; i++)
				this->_allocator.construct(_begin + i, val);
			this->_size = n;
		}

		void
		push_back(const T& val)
		{
			if (this->_size >= this->_capacity)
			{
				if (this->_capacity == 0)
					this->reserve(1);
				else
					this->reserve(this->_capacity * 2);
			}
			_allocator.construct(this->_begin + this->_size, val);
			this->_size++;
		}
		
		void
		pop_back()
		{
			if (!this->_size)
				return ;
			this->_allocator.destroy(this->_begin + this->_size - 1);
			this->_size--;
			// 	_allocator.deallocate(_begin, _capacity);
		}

		iterator
		insert(iterator position, const T& val)		 // inserting new elements before the element at the specified position
		{
			difference_type	pos = position - this->begin();
			
			if (this->_capacity == 0)
				this->reserve(1);
			else if (this->_size >= this->_capacity)
				this->reserve(this->_capacity * 2);
			
			int			x = 1;
			for (long i = this->_size; i > pos; i--, x++ )
			{
				this->_allocator.construct(this->begin() + i, *(this->end() - x));
				this->_allocator.destroy(this->end() - x);
			}

			this->_allocator.construct(this->begin() + pos, val);
			this->_size++;
			return (this->begin() + pos);
		}
		
		
		void
		insert(iterator position, size_type n, const value_type& val)			// fill reutiliser le premier
		{
			if (n == 0)
				return ;
			difference_type	pos = position - this->begin();
			
			if (this->_size + n >= this->_capacity * 2)
				this->reserve(this->_size + n);
			else if (this->_size + n > this->_capacity)
					this->reserve(this->_size * 2);

			for (size_t m = 0; m < n; m++)
				this->insert(this->begin() + pos + m, val);			
		}

		template <class InputIterator>
		void
		insert(iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)	// range
		{
			difference_type		pos = std::distance(this->_begin, position);
			difference_type		count = std::distance(first, last);
			size_t m = 0;

			if (this->_size + count > this->_capacity * 2)
				this->_capacity = this->_size + count;
			else if (this->_size + count >= this->_capacity)
				this->_capacity = this->_size * 2;
			
			pointer temp = this->_allocator.allocate(_capacity);

			for (; m < (size_t)pos; m++)
				this->_allocator.construct(temp + m, *(this->_begin + m));  // copy first to pos of current vector

			for (; first != last; first++, m++)
				this->_allocator.construct(temp + m, *first);	// insert 

			for (; (size_t)pos < this->_size; pos++, m++)
				this->_allocator.construct(temp + m, *(this->_begin + pos));	//copy pos to last of current vector
			
			if (this->_capacity)
			{
				for (size_t i = 0;i < this->_size; i++)
					this->_allocator.destroy(this->_begin + i);
			}
			this->_allocator.deallocate(this->_begin, this->_capacity);
			this->_begin = temp;
			this->_size += count; 
		}
		
		iterator
		erase (iterator position)				    // erase single element. On destroy ce qu'il y a à position puis on y met la valeur de position + 1. On itere jusqu'a la fin du vector.
		{
			iterator	temp = position;
			for (; position + 1 != this->end(); position++)
			{
				this->_allocator.destroy(position);
				this->_allocator.construct(position, *(position + 1));
			} 
			this->_allocator.destroy(position);		// on destroy le dernier iterator du vector.
			this->_size--;
			return (temp);
		}
		
		iterator
		erase (iterator first, iterator last)		// erase range
		{
			for (; first != last; last--)
				this->erase(first);
			return (first);
		}
		
		void
		swap(vector& x)							// non-member function exists
		{
			size_type			_temp_size = _size;
			size_type			_temp_capacity = _capacity;
			allocator_type		_temp_allocator = _allocator;
			pointer				_temp_begin = _begin;

			_size = x._size;
			_capacity = x._capacity;
			_allocator = x._allocator;
			_begin = x._begin;

			x._size = _temp_size;
			x._capacity = _temp_capacity;
			x._allocator = _temp_allocator;
			x._begin = _temp_begin;
		}
		
		void
		clear()		// Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
		{
			for (size_t i = 0; i < _size; i++)
				_allocator.destroy(_begin + i);
			// _allocator.deallocate(_begin, _capacity);
			this->_size = 0;
		}
		/***************** Allocator *****************/
		T			get_allocator() const { return (this->_allocator); }

	protected:
		/* ****************************************************************************************** */
		/**************************************** MEMBER DATAS ****************************************/
		size_type			_size;
		size_type			_capacity;
		// value_type			_value;
		allocator_type		_allocator;
		pointer				_begin;
		// pointer				_end; //? ok de looper a chaque fois (begin + _size)
	};

	/* ****************************************************************************************** */
	/**************************************** OPERATORS ****************************************/

	template<class T, class Alloc>
	bool 
	operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size()) // need ft_equal
			return (false);
		if ( ! ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
				return (false);
		return (true);
	}

	template<class T, class Alloc>
	bool
	operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T, class Alloc>
	bool
	operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class T, class Alloc>
	bool
	operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{	
		if (lhs < rhs || lhs == rhs)
			return (true);
		return (false);
	}

	template<class T, class Alloc>
	bool
	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs <= rhs)
			return (false);
		return (true);
	}

	template<class T, class Alloc>
	bool
	operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs < rhs)
			return (false);
		return (true);
	}

	template<class T, class Alloc>
	void
	swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}

};

#endif