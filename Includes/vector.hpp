// #pragma once

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <stdexcept>
# include "iterators.hpp"
# include "reverse_iterators.hpp"
# include "equal.hpp"
# include "lexicographical_compare.hpp"



// #include "reverse_iterators.hpp"

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
		typedef size_t										size_type;
		typedef ptrdiff_t									difference_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef T*											iterator;
		typedef const T*									const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		/* ****************************************************************************************** */
		/************************************** MEMBER FUNCTIONS **************************************/
		
		/***************** Constructors / Destructor *****************/

		/* default constructor */
		vector(const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _value(0), _allocator(alloc), _begin(NULL), _end(NULL)
		{}

		/* fill constructor */
		vector(size_type n, const T& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _value(val), _allocator(alloc),
																							_begin(_allocator.allocate(n, 0)), _end(_begin + n) 
		{
			for (size_t i = 0; i < n ; i++)
				_allocator.construct(_begin + i, val);
		}

		/* range constructor */
		template <class InputIterator>
		vector( InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type())
													: _size(std::distance(first, last)), _capacity(std::distance(first, last)), _value(0), _allocator(alloc),
													_begin(_allocator.allocate(std::distance(first, last), 0)), _end(first + std::distance(first, last))
		{
			for (size_t i = 0; first != last; i++, first++)
				_allocator.construct(_begin + i, *(first));
		}

		/* copy constructor */
		vector(const vector& cpy)
		{
			this->_size = cpy._size;
			this->_capacity = cpy._capacity;
			this->_value = cpy._value;
			this->_allocator = cpy._allocator;
			this->_begin = _allocator.allocate(this->_capacity, 0);
			this->_end = this->_begin + this->_size;

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
			if (this->_capacity < assign._size)
			{
				this->_size = assign._size;
				this->_capacity = assign._capacity;
				this->_value = assign._value;
				this->_allocator = assign._allocator;
				this->_begin = _allocator.allocate(this->_capacity, 0);
				this->_end = this->_begin + this->_capacity;
				
				for (size_t i = 0; i < _size; i++)
					_allocator.construct(this->_begin + i, *(assign._begin + i));
			}
			else
			{
				this->_size = assign._size;
				for (size_t i = 0; i < _size; i++)
					_allocator.construct(this->_begin + i, *(assign._begin + i));
			}
			return (*this);	
		}

		/***************** Iterators *****************/

		iterator
		begin() { return (this->_begin); }
		
		iterator
		begin() const { return (this->_begin); }

		iterator
		end() { return (this->_begin + this->_size); }

		iterator
		end() const { return (this->_begin + this->_size); }

		/***************** Capacity *****************/

		size_type
		size() const { return (this->_size); }
		
		size_type
		max_size() const { return (this->_allocator.max_size()); }  // maximum potential size the container can reach due to known system
		
		void
		resize(size_type n, value_type val = value_type())     // Resizes the container so that it contains n elements. "val" is optional
		{
			if (n < this->_size)
			{
				while (n < this->_size)
					this->pop_back();
			}
			else if (n > this->_size)
			{
				while (n > this->_size)
				{
					if (val)
						this->push_back(val);
					this->push_back(0);
				}
			}
			else if (n > this->_capacity)
				reserve(n);
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
			else if (n > this->max_size())
				throw std::length_error("Reserve: n is superior to Max_size");
			
			pointer	temp = _allocator.allocate(n);
			for (size_t i = 0; i < _size; i++)
					_allocator.construct(temp + i, *(_begin + i));
			
			if (_capacity != 0)
			{
				for (size_t i = 0; i < _size; i++)
					_allocator.destroy(_begin + i);
				_allocator.deallocate(_begin, _capacity);
			}
			this->_begin = temp;
			this->_end = this->_begin + this->_size;
			this->_capacity = n;
		}

		/***************** Element access *****************/

		T&			
		operator[](size_type n)	{ return (*(this->_begin + n)); }	 // should never call this function with an argument n that is out of range ==> undefined behavior.

		const T&
		operator[](size_type n) const { return (*(this->_begin + n)); }

		T&
		at(size_type n)
		{
			if (n <= this->_size)
				return (*(this->_begin + n));
			else
				throw std::out_of_range("Requested index is out of range");
		}
		
		const T&
		at(size_type n) const
		{
			if (n <= this->_size)
				return (*(this->_begin + n));
			else
				throw std::out_of_range("Requested index is out of range");
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
			for (size_t i = 0; first != last; ++first, ++i)
				this->_allocator.construct(this->_begin, *first);
			this->_size = distance;
		}
		
		void
		assign(size_type n, const T& val)			// In the fill version (2), the new contents are n elements, each initialized to a copy of val.
		{
			this->clear();
			for (size_t i = 0; i < n; i++)
				this->push_back(val);
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
			this->_end++; //?
			_allocator.construct(this->_end - 1, val);
			this->_size++;
		}
		
		void
		pop_back()
		{
			if (!this->_size)
				return ;
			this->_allocator.destroy(this->_end - 1);
			this->_end--;
			this->_size--;
			// 	_allocator.deallocate(_begin, _capacity);
		}

		iterator
		insert(iterator position, const T& val)		 // inserting new elements before the element at the specified position
		{
			ptrdiff_t	pos = position - this->begin();
			
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
			ptrdiff_t	pos = position - this->begin();
			
			if (this->_size + n >= this->_capacity)
			{
				if (this->_size + n > this->_capacity * 2)
					this->reserve(this->_size + n);
				else
					 this->reserve(this->_size * 2);
			}
			for (size_t m = 0; m < n; m++)
				this->insert(this->begin() + pos + m, val);			
		}

		template <class InputIterator>
		void
		insert(InputIterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)	// range
		{
			ptrdiff_t	pos = std::distance(this->_begin, position);
			ptrdiff_t	count = std::distance(first, last);
			// size_t		i = 0;

			if (this->_size + count >= this->_capacity)
			{
				if (this->_size + count > this->_capacity * 2)
					this->reserve(this->_size + count);
				else
					 this->reserve(this->_size * 2);
			}
			for (size_t m = 0; first != last; first++, m++)
				this->insert(this->_begin + pos + m, *first);
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
			value_type			_temp_value = _value;
			allocator_type		_temp_allocator = _allocator;
			pointer				_temp_begin = _begin;
			pointer				_temp_end = _end;

			_size = x._size;
			_capacity = x._capacity;
			_value = x._value;
			_allocator = x._allocator;
			_begin = x._begin;
			_end = x._end;

			x._size = _temp_size;
			x._capacity = _temp_capacity;
			x._value = _temp_value;
			x._allocator = _temp_allocator;
			x._begin = _temp_begin;
			x._end = _temp_end;
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

	// private:
		/* ****************************************************************************************** */
		/**************************************** MEMBER TYPES ****************************************/
		size_type			_size;
		size_type			_capacity;
		value_type			_value;
		allocator_type		_allocator;
		pointer				_begin;
		pointer				_end; //? ok de looper a chaque fois (begin + _size)
	};

	/* ****************************************************************************************** */
	/**************************************** OPERATORS ****************************************/

	template<class T, class Alloc>
	bool 
	operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs._size() != rhs.size()) // need ft_equal
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