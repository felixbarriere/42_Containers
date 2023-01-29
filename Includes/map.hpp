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


# include <iostream>
# include <iterator>
# include "reverse_iterators.hpp"
# include "lexicographical_compare.hpp"
# include "pair.hpp"
# include "node_struct.hpp"
# include "null_ptr.hpp"
# include "red_black_tree.hpp"
# include "iterators_map.hpp"
// # include <stdexcept>


namespace ft
{
    template < typename Key, typename Value, typename Compare = std::less<Key>,
                typename Allocator = std::allocator<std::pair<const Key, Value> > >
    class map
    {
    public:
        /* ****************************************************************************************** */
		/****************************************** ALIASES *******************************************/

        typedef Key                                 			key_type;	                                
        typedef Value                                   		mapped_type;
        typedef ft::pair<const Key, Value>              		value_type;	       //change to ft                         
        typedef std::size_t                         			size_type;	                                 
        typedef std::ptrdiff_t                      			difference_type;                        
        typedef Compare                             			key_compare;                              
        typedef Allocator                           			allocator_type;	                            
        typedef value_type&                         			reference;	                                
        typedef const value_type&                   			const_reference;	                            
        typedef typename Allocator::pointer         			pointer;	         //typename tells the compiler that an unknown identifier is a type (cf Allocator).                           
        typedef typename Allocator::const_pointer   			const_pointer;	
        typedef typename ft::iterator_map<value_type, ft::node<value_type> >   			iterator;	
        typedef typename ft::iterator_map<const value_type, ft::node<value_type> >   	const_iterator;	


		/* Nested Class */
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;
		
			protected:
				key_compare	comp;
				value_compare(key_compare c) : comp(c) {};
			public:
				typedef	bool result_type;
				bool	operator()(const value_type& x, const value_type& y) const
				{ return comp(x.first, y.first); }  // first ==>cf ft::pair
		};           

		typedef	typename ft::RBT<value_type, value_compare>		RBT;
        // typedef value_type                             			iterator;
        // typedef const value_type                       const_iterator;             
        typedef ft::reverse_iterator<iterator>         reverse_iterator;         //change to ft         
        typedef ft::reverse_iterator<const_iterator>   const_reverse_iterator;   //change to ft  




		/* ****************************************************************************************** */
		/**************************************** MEMBER DATAS ****************************************/
    protected:
		allocator_type		_allocator;
		value_compare		_comp;
        size_type			_size;
		// size_type			_capacity;
		// pointer				_root;
		RBT					_RBT;

        /* ****************************************************************************************** */
		/****************************************** CONSTRUCTORS **************************************/
    public:    
		explicit
        map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					: _allocator(alloc), _comp(value_compare(comp)), _size(0), _RBT(_comp)
		{
			std::cout << "********************************** CONSTRUCTOR **********************************" << std::endl;

		}

        // template <class InputIterator>
        // map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
		// const allocator_type& alloc = allocator_type()); 

        map (const map& x)
		{ 
			std::cout << "********************************** COPY CONSTRUCTOR **********************************" << std::endl;
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
			(void)x;
			return (*this);
		}

        /* ****************************************************************************************** */
		/****************************************** MEMBER FUNCTIONS **********************************/

		/* Iterators */
		iterator begin();const_iterator begin() const;

		iterator
		end()
		{
			return (iterator(_RBT.getLeafNULL(), _RBT.getRoot(), _RBT.getLeafNULL()));
		}
		
		const_iterator end() const;
		
		reverse_iterator rbegin();const_reverse_iterator rbegin() const;
		reverse_iterator rend();const_reverse_iterator rend() const;
		const_iterator cbegin() const;
		const_iterator cend() const;
		const_reverse_iterator crbegin() const;
		const_reverse_iterator crend() const;

		/* Capacity */

		bool empty() const;
		
		
		size_type size() const { return ( this->_size); }



		size_type max_size() const;

		/* Element access */

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

		/* Modifiers */

		ft::pair<iterator, bool>
		insert (const value_type &val)   //need make_pair
		{ 
			std::cout << "********************************** ICI1 **********************************" << std::endl;

			if (_RBT.insert(val) == ft::null_ptr)
			{
			std::cout << "********************************** ICI MAP **********************************" << std::endl;

				return (ft::make_pair(iterator(_RBT.find(_RBT.getRoot(), val), _RBT.getRoot(), _RBT.getLeafNULL()), false));
			}
			_size++;
			return (ft::make_pair(iterator(_RBT.find(_RBT.getRoot(), val), _RBT.getRoot(), _RBT.getLeafNULL()), true));
		}

		// iterator
		// insert (iterator position, const value_type& val);

		// template <class InputIterator>
		// void
		// insert (InputIterator first, InputIterator last);

		void erase (iterator position);
		
		size_type erase (const key_type& k);
		
		void erase (iterator first, iterator last);

		void swap (map& x);

		void clear();

		/* Observers */

		key_compare
		key_comp() const;
		
		value_compare
		value_comp() const;

		/* Operations */

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
		count (const key_type& k) const;
		
		iterator
		lower_bound (const key_type& k);
		const_iterator lower_bound (const key_type& k) const;
		
		iterator
		upper_bound (const key_type& k);
		const_iterator upper_bound (const key_type& k) const;
		
		pair<const_iterator,const_iterator>
		equal_range (const key_type& k) const;
		
		pair<iterator,iterator>
		equal_range (const key_type& k);

		/* Allocator */

		allocator_type get_allocator() const;

    };


	/* ****************************************************************************************** */
	/**************************************** NON-MEMBER OPERATORS ********************************/

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
};

#endif