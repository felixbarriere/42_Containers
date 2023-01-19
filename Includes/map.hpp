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
# include "utils/pair.hpp"
# include "utils/node_struct.hpp"
# include "utils/null_ptr.hpp"
# include "utils/red_black_tree.hpp"
// # include <stdexcept>


namespace ft
{
    template < typename Key, typename T, typename Compare = std::less<Key>,
                typename Allocator = std::allocator<std::pair<const Key, T> > >
    class map
    {
    public:
        /* ****************************************************************************************** */
		/****************************************** ALIASES *******************************************/

        typedef Key                                 key_type;	                                
        typedef T                                   mapped_type;
        typedef ft::pair<const Key, T>              value_type;	       //change to ft                         
        typedef std::size_t                         size_type;	                                 
        typedef std::ptrdiff_t                      difference_type;                        
        typedef Compare                             key_compare;                              
        typedef Allocator                           allocator_type;	                            
        typedef value_type&                         reference;	                                
        typedef const value_type&                   const_reference;	                            
        typedef typename Allocator::pointer         pointer;	         //typename tells the compiler that an unknown identifier is a type (cf Allocator).                           
        typedef typename Allocator::const_pointer   const_pointer;	                            
        
        typedef value_type                              iterator;
        typedef const value_type                        const_iterator;             
        typedef std::reverse_iterator<iterator>         reverse_iterator;         //change to ft         
        typedef std::reverse_iterator<const_iterator>   const_reverse_iterator;   //change to ft  

		/* ****************************************************************************************** */
		/**************************************** NESTED CLASS ****************************************/
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

        /* ****************************************************************************************** */
		/****************************************** CONSTRUCTORS **************************************/
        explicit
        map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					: _allocator(alloc), _comp(comp), _size(0), _capacity(0), _root()
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
		iterator end();const_iterator end() const;
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

		mapped_type& operator[] (const key_type& k);
		mapped_type& at (const key_type& k);const mapped_type& at (const key_type& k) const;

		/* Modifiers */

		pair<iterator,bool>
		insert (const value_type& val)   //need make_pair
		{ (void)val; }

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
		find (const key_type& k);const_iterator find (const key_type& k) const;
		
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

        /* ****************************************************************************************** */
		/**************************************** MEMBER DATAS ****************************************/
    protected:
		allocator_type		_allocator;
		key_compare			_comp;
        size_type			_size;
		size_type			_capacity;
		pointer				_root;




    };


	/* ****************************************************************************************** */
	/**************************************** NON-MEMBER OPERATORS ********************************/
};

#endif