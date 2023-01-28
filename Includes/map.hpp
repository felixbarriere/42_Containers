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
        typedef value_type                             			iterator;
        typedef const value_type                       			const_iterator;             
        typedef ft::reverse_iterator<iterator>         reverse_iterator;         //change to ft         
        typedef ft::reverse_iterator<const_iterator>   const_reverse_iterator;   //change to ft  




		/* ****************************************************************************************** */
		/**************************************** MEMBER DATAS ****************************************/
    protected:
		allocator_type		_allocator;
		key_compare			_comp;
        size_type			_size;
		size_type			_capacity;
		pointer				_root;
		RBT					_RBT;

        /* ****************************************************************************************** */
		/****************************************** CONSTRUCTORS **************************************/
    public:    
		explicit
        map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					: _allocator(alloc), _comp(comp), _size(0), _capacity(0), _root(), _RBT(comp)
		{}

        // template <class InputIterator>
        // map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
		// const allocator_type& alloc = allocator_type()); 

        // map (const map& x);

		// ~map();

		map& operator= (const map& x);

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
		size_type size() const;
		size_type max_size() const;

		/* Element access */

		mapped_type& operator[] (const key_type& k)
		{
			iterator it = find(k);
			if ( it == end() )
			{
				insert(make_pair(k,mapped_type()));
				it = find (k);
			}
			return (it->second);
		}



		mapped_type& at (const key_type& k);const mapped_type& at (const key_type& k) const;

		/* Modifiers */

		pair<iterator, bool>
		insert (const value_type& val)   //need make_pair
		{ 
			// (void)val;



			_RBT.insert(val);
				
		}

		iterator
		insert (iterator position, const value_type& val);

		template <class InputIterator>
		void
		insert (InputIterator first, InputIterator last);

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
			return (iterator(_RBT.find(k), _RBT.getRoot(), _RBT.getLeafNULL()));
		}
		
		const_iterator
		find (const key_type& k) const
		{
			return (_RBT.find(k));
		}
		
		size_type
		count (const key_type& k) const;
		
		iterator
		lower_bound (const key_type& k);const_iterator lower_bound (const key_type& k) const;
		
		iterator
		upper_bound (const key_type& k);const_iterator upper_bound (const key_type& k) const;
		
		pair<const_iterator,const_iterator>
		equal_range (const key_type& k) const;
		
		pair<iterator,iterator>
		equal_range (const key_type& k);

		/* Allocator */

		allocator_type get_allocator() const;

        /* ****************************************************************************************** */
		/****************************************** INSIDE OPERATIONS *********************************/
        /* left_rotate */
        /* right_rotate */
        /* insert */
        /* delete */






    };


	/* ****************************************************************************************** */
	/**************************************** NON-MEMBER OPERATORS ********************************/
};

#endif