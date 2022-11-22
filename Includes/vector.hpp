

template < typename T, typename Alloc = std::allocator<T> >
class vector
{
		/************ Aliases ***********/
	public:
		typedef T												value_type;
		typedef Alloc											allocator_type;
		typedef size_t										size_type;
		typedef ptrdiff_t										difference_type;
		typedef allocator_type::reference						reference;
		typedef allocator_type::const_reference				const_reference;
		typedef allocator_type::pointer						pointer;
		typedef allocator_type::const_pointer					const_pointer;
		typedef iterator										iterator;
		typedef const_iterator								const_iterator;
		typedef reverse_iterator<iterator>					reverse_iterator;
		typedef reverse_iterator<const_iterator>				const_reverse_iterator;

		

		/********** member functions **********/


		/* Constructors / Destructor */

		vector(const allocator_type& alloc = allocator_type() : _size(0), _capacity(0)) //default constructor
		{
			_value = NULL;
			_begin = NULL;
			_end =  NULL;
			_allocator = NULL; //?
		}

		vector(size_type n, const T& val, const allocator_type& alloc = allocator_type()) : _size(n), _capacity(0), _value(val) 	// fill constructor: Each of the n elements in the container will be initialized to a copy of this value.
		{
			_begin = NULL;
			_end =  NULL;
			_allocator = NULL; //?
		}
		vector(iterator first, iterator last, const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _begin(first), _end(last)		// range constructor
		{
			_value = NULL;
			_allocator = NULL; //?
		}
		vector(const vector& cpy); 					// copy constructor
		~vector();

		vector&	operator=(const vector&);

		/* Iterators */

		// iterator	begin(); cf cpp_08

		

		/* Capacity */
		size_type	size() const;
		size_type	max_size() const;            // maximum potential size the container can reach due to known system or library implementation limitations
		void		resize(size_type n, T val);     // Resizes the container so that it contains n elements. "val" is optional
		size_type	capacity() const;            // Return size of allocated storage capacity
		bool		empty() const;
		void		reserve(size_type n);           // Requests that the vector capacity be at least enough to contain n elements.

		/* Element access */
		T&			operator[](size_type n);		 // should never call this function with an argument n that is out of range ==> undefined behavior.
		const T&	operator[](size_type n) const;
		T&			at(size_type n);				 // throwing an out_of_range exception if it is not
		const T&	at(size_type n) const;
		T&			front();					 // Unlike member vector::begin, which returns an iterator to this same element, this function returns a direct reference.
		const T&	front() const;
		T&			back();
		const T&	back() const;
		T*			data() noexcept;			 // Returns pointer to the underlying array serving as element storage. a confirmer
		const T*	data() const noexcept;

		/* Modifiers */
		T			assign(Iterator first, Iterator last);	// Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
		void		assign(size_type n, const T& val);			// In the fill version (2), the new contents are n elements, each initialized to a copy of val.
		void 		push_back(const T& val);
		void		pop_back();
		iterator	insert(iterator/member_type position, const T& val);		 // inserting new elements before the element at the specified position
		void		insert(iterator/member_type position, size_type n, const value_type& val);   		// fill reutiliser le premier
		void		insert(iterator/member_type position, iterator first, iterator last);				// range
		iterator 	erase (iterator position);				    // erase single element
		iterator 	erase (iterator first, iterator last);		// erase range
		void		swap(vector& x);							// non-member function exists
		void		clear();		// Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.

		/* Allocator */
		T			get_allocator() const;
	private:
		/************ Member types ***********/
		size_type			_size;
		size_type			_capacity;
		value_type			_value;
		allocator_type		_allocator;
		pointer				_begin;
		pointer				_end; //? ok de looper a chaque fois (begin + _size)
};

template<class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template<class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template<class T, class Alloc>
bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template<class T, class Alloc>
bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template<class T, class Alloc>
bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template<class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);