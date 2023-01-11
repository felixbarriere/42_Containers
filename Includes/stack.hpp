// #pragma once

#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <iterator>
// # include <stdexcept>

# include "iterators.hpp"
# include "reverse_iterators.hpp"
# include "equal.hpp"
# include "lexicographical_compare.hpp"
# include "enable_if.hpp"
# include "equal.hpp"
# include "vector.hpp"

// std::is_integral<int>::value;

namespace ft
{
	template < typename T, typename Container = ft::vector<T> >
	class stack
	{
	public:
		/* ****************************************************************************************** */
		/****************************************** ALIASES *******************************************/

		typedef T											value_type;
		typedef std::size_t									size_type;
		typedef Container									container_type;


		/* ****************************************************************************************** */
		/************************************** MEMBER FUNCTIONS **************************************/
		
		/***************** Constructors / Destructor *****************/

		/* default constructor */
		explicit
		stack(const container_type& cntr = container_type()) : _c(cntr) {}

		~stack() {}

		/***************** Member functions *****************/

		bool
		empty() const {return (this->_c.empty()); }

		size_type
		size() const { return (this->_c.size()); }

		value_type&
		top() { return (this->_c.back()); }
		
		const value_type&
		top() const { return (this->_c.back()); }

		void 
		push (const value_type& val) { return (this->_c.push_back(val)); }

		void
		pop() { return (this->_c.pop_back()); }

		/* ****************************************************************************************** */
		/**************************************** MEMBER TYPES ****************************************/
		
		protected:
			container_type			_c; //underlying container

		/* ****************************************************************************************** */
		/**************************************** OPERATORS PROTOTYPES ****************************************/

		template <class T2, class Container2>
		friend bool 
		operator==(const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs);
		
		template <class T2, class Container2>
		friend bool
		operator!=(const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs);


		template <class T2, class Container2>
		friend bool
		operator<(const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs);


		template <class T2, class Container2>
		friend bool
		operator<=(const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs);

		template <class T2, class Container2>
		friend bool
		operator>(const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs);

		template <class T2, class Container2>
		friend bool
		operator>=(const ft::stack<T2,Container2>& lhs, const ft::stack<T2,Container2>& rhs);
	};

	/* ****************************************************************************************** */
	/**************************************** OPERATORS ****************************************/

	template <class T, class Container>
	bool 
	operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		if (lhs._c == rhs._c)
			return (true);
		return (false);
	}

	template <class T, class Container>
	bool
	operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Container>
	bool
	operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		if (lhs._c < rhs._c)
			return (true);
		return (false);
	}

	template <class T, class Container>
	bool
	operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{	
		return (lhs._c <= rhs._c);
	}

	template <class T, class Container>
	bool
	operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (lhs._c > rhs._c);
	}

	template <class T, class Container>
	bool
	operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (lhs._c >= rhs._c);
	}
};

#endif