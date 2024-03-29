/* Red Black Tree:
- Red/Black Property: Every node is colored, either red or black.
- Root Property: The root is black.
- Leaf Property: Every leaf (NIL) is black.
- Red Property: If a red node has children then, the children are always black.
- Depth Property: For each node, any simple path from this node to any of 
    its descendant leaf has the same black-depth (the number of black nodes).
*/

/* Compare: A binary predicate that takes two element keys as arguments 
and returns a bool. The expression comp(a,b), where comp is an object of 
this type and a and b are key values, shall return true if a is considered 
to go before b in the strict weak ordering the function defines. */

#ifndef MAP_HPP
# define MAP_HPP

# define BLACK 0
# define RED 1

# include <limits>

# include <iostream>
# include <iterator>
# include "reverse_iterators.hpp"
# include "enable_if.hpp"
# include "lexicographical_compare.hpp"
# include "pair.hpp"
# include "equal.hpp"
# include "node_struct.hpp"
# include "null_ptr.hpp"
# include "red_black_tree.hpp"
# include "iterators_map.hpp"
// # include <stdexcept>


namespace ft
{
    template < class Key, class Value, class Compare = std::less<Key>, 
										class Allocator = std::allocator<ft::pair<const Key, Value> > >
    class map
    {
    public:
        /* ****************************************************************************************** */
		/****************************************** ALIASES *******************************************/

        typedef Key                                 			key_type;	                                
        typedef Value                                   		mapped_type;
        typedef ft::pair<const Key, Value>              		value_type;	                          
        typedef std::size_t                         			size_type;	                                 
        typedef std::ptrdiff_t                      			difference_type;   //result of subtracting two pointers              
        typedef Compare                             			key_compare;                              
        typedef Allocator                           			allocator_type;	                            
        typedef value_type&                         			reference;	                                
        typedef const value_type&                   			const_reference;	                            
        typedef typename Allocator::pointer         			pointer;	         //typename tells the compiler that an unknown identifier is a type (cf Allocator).                           
        typedef typename Allocator::const_pointer   			const_pointer;	
        typedef typename ft::iterator_map<value_type, Node<value_type> >   			iterator;	
        typedef typename ft::iterator_map<const value_type, Node<value_type> >   	const_iterator;	


		/* Nested Class */
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;
		
			protected:
				key_compare	comp;
				value_compare(key_compare c) : comp(c) {};
			public:
				typedef	bool result_type;
				typedef value_type	first_arg;
				typedef value_type	second_arg;

				bool	operator()(const value_type& x, const value_type& y) const
				{ return comp(x.first, y.first); }  // first ==>cf ft::pair
		};           

		typedef	typename ft::RBT<value_type, value_compare>		RBT;
        typedef ft::reverse_iterator<iterator>         			reverse_iterator;           
        typedef ft::reverse_iterator<const_iterator>   			const_reverse_iterator;  




		/* ****************************************************************************************** */
		/**************************************** MEMBER DATAS ****************************************/
    protected:
		allocator_type		_allocator;
		value_compare		_comp;
        size_type			_size;
		RBT					_RBT;

        /* ****************************************************************************************** */
		/****************************************** CONSTRUCTORS **************************************/
    public:    
		explicit
        map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					: _allocator(alloc), _comp(value_compare(comp)), _size(0), _RBT(_comp)
		{
		}

        template <class InputIterator>
        map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
								: _allocator(alloc), _comp(value_compare(comp)), _size(0), _RBT(_comp) 
		{
			insert(first, last);
		} 

        map (const map& x) : _allocator(x._allocator), _comp(x._comp), _size(x._size), _RBT(_comp)
		{ 
			*this = x;
		}

		~map()
		{
			if (_size != 0)
				_RBT.delete_tree(_RBT.getRoot());
			_RBT.delete_LEAF_NULL();
		}

		map& operator=(const map& x)
		{
			if (this == &x)
				return (*this);
			_comp = x._comp;
			_allocator = x._allocator;
			_RBT.delete_tree(_RBT.getRoot());
			insert(x.begin(), x.end());
        	_size = x._size;

			return (*this);
		}

        /* ****************************************************************************************** */
		/****************************************** MEMBER FUNCTIONS **********************************/

		/* ******************* Iterators ******************* */
		iterator
		begin() 
		{ return(iterator(_RBT.begin(), _RBT.getRoot(), _RBT.getLeafNULL())) ; }
		
		const_iterator begin() const
		{ return(const_iterator(_RBT.begin(), _RBT.getRoot(), _RBT.getLeafNULL())) ; }

		iterator
		end()
		{ return (iterator(_RBT.getLeafNULL(), _RBT.getRoot(), _RBT.getLeafNULL())); }
		
		const_iterator end() const
		{ return (const_iterator(_RBT.getLeafNULL(), _RBT.getRoot(), _RBT.getLeafNULL())); }
		
		reverse_iterator
		rbegin() { return (reverse_iterator(end())); }
		
		const_reverse_iterator 
		rbegin() const {  return (const_reverse_iterator(end())); }

		reverse_iterator
		rend() { return (reverse_iterator(begin())); }
		
		const_reverse_iterator
		rend() const { return (const_reverse_iterator(begin())); }


		/* ******************* Capacity ******************* */

		bool empty() const { return (_RBT.getRoot() == _RBT.getLeafNULL()); }	//std::map::empty
		
		
		size_type size() const { return ( this->_size); }

		size_type max_size() const { return ( _RBT.max_size() ); }

		/* ******************* Element access ******************* */

		mapped_type& operator[] (const key_type& k)
		{
			iterator it = find(k);
			if ( it == end() )
			{
				insert(value_type(k,mapped_type()));
				it = find (k);
			}
			
			return (it->second);
		}

		mapped_type& at (const key_type& k);
		const mapped_type& at (const key_type& k) const;

		/* ******************* Modifiers ******************* */

		ft::pair<iterator, bool>
		insert (const value_type &val)   //need make_pair
		{ 
			if (_RBT.insert(val) == ft::null_ptr)
			{
				return (ft::make_pair(iterator(_RBT.find(_RBT.getRoot(), val), _RBT.getRoot(), _RBT.getLeafNULL()), false));
			}
			_size++;
			return (ft::make_pair(iterator(_RBT.find(_RBT.getRoot(), val), _RBT.getRoot(), _RBT.getLeafNULL()), true));
		}

		iterator
		insert (iterator position, const value_type& val)   //hint
		{
			(void)position;
			insert(val);
			return (iterator(_RBT.find(_RBT.getRoot(), val), _RBT.getRoot(), _RBT.getLeafNULL()));
		}

		template <class InputIterator>
		void
		insert (InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(*first);
				first++;
			}
		}

		void erase (iterator position)
		{
			if (_size == 0)
				return ;
			if ( _RBT.deleteNode(*position))
				_size--;
		}
		
		size_type erase (const key_type& k)
		{
			if (_size == 0)
				return (0);
			iterator it = find(k);
			if (it == end())
				return (0);
			erase(it);
			return (1);
		}
		
		void erase (iterator first, iterator last)
		{
			iterator tmp = first;
			while (first != last)
			{
				tmp = first;
				first++;
				erase(tmp->first);
			}
		}

		void swap (map& x)
		{
			size_t tmp = x._size;
			x._size = _size;
			_size = tmp;

			swap2(_RBT, x._RBT);
		}
		
		template <class T>
		void swap2 (T& RBT, T& RBT2)
		{
			T	tmp = RBT2;
			RBT2 = RBT;
			RBT = tmp;
		}

		void clear()
		{
			if (_size != 0)
			{
				_RBT.clear();
				_size = 0;
			}
		}

		/* ******************* Observers ******************* */

		key_compare
		key_comp() const
		{
			return (key_compare());
		}
		
		value_compare
		value_comp() const
		{
			return (_comp);
		}

		/* ******************* Operations ******************* */

		iterator	
		find (const key_type& k)
		{
			return (iterator(_RBT.find(_RBT.getRoot(), value_type(k, mapped_type())), _RBT.getRoot(), _RBT.getLeafNULL()));
		}
		
		const_iterator
		find (const key_type& k) const
		{
			return (iterator(_RBT.find(_RBT.getRoot(), value_type(k, mapped_type())), _RBT.getRoot(), _RBT.getLeafNULL()));
		}
		
		size_type
		count (const key_type& k) const
		{
			if (find(k) == end())
				return (0);
			return (1);
		}
		
		// returns an iterator pointing to the key in the map container which is equivalent to k
		iterator
		lower_bound (const key_type& k)
		{
			return (iterator(_RBT.lower_bound(value_type(k, mapped_type()))
																		,_RBT.getRoot(), _RBT.getLeafNULL()));
		}

		const_iterator 
		lower_bound (const key_type& k) const
		{
			return (const_iterator(_RBT.lower_bound(value_type(k, mapped_type()))
																		, _RBT.getRoot(), _RBT.getLeafNULL()));
		}
		
		// returns an iterator pointing to the immediate next element just greater than k.
		iterator
		upper_bound (const key_type& k)
		{
			return (iterator(_RBT.upper_bound(value_type(k, mapped_type()))
																		,_RBT.getRoot(), _RBT.getLeafNULL()));
		}

		const_iterator 
		upper_bound (const key_type& k) const
		{
			return (const_iterator(_RBT.upper_bound(value_type(k, mapped_type()))
																		, _RBT.getRoot(), _RBT.getLeafNULL()));
		}
		
		ft::pair<const_iterator,const_iterator>
		equal_range (const key_type& k) const
		{
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}
		
		ft::pair<iterator,iterator>
		equal_range (const key_type& k)
		{
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}

		/* ******************* Allocator ******************* */

		allocator_type get_allocator() const { return (_allocator); }

		void 
		printTree()
		{
			_RBT.printTree();
		}

    };


	/* ****************************************************************************************** */
	/**************************************** NON-MEMBER OPERATORS ********************************/

	template <class Key, class T, class Compare, class Alloc>
	bool	operator==(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs < rhs) && !(lhs > rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator!=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return (! ( lhs > rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return (!( lhs < rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	void	swap(ft::map<Key, T, Compare, Alloc>& lhs, ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return (lhs.swap(rhs));
	}
};

#endif