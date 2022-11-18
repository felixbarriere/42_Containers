

template < typename T, typename Alloc = std::allocator<T> >
class vector
{
	public:
		/************ Member types ***********/







		/********** member functions **********/


		/* Constructors / Destructor */
		vector(); //default constructor
		vector(size_t n, const T& val); 			// fill constructor: Each of the n elements in the container will be initialized to a copy of this value.
		vector(iterator first, iterator last); 		// range constructor
		vector(const vector& cpy); 					// copy constructor
		~vector();

		vector&	operator=(const vector&);

		/* Iterators */

		// iterator	begin(); cf cpp_08

		

		/* Capacity */
		size_t	size() const;
		size_t	max_size() const;            // maximum potential size the container can reach due to known system or library implementation limitations
		void	resize(size_t n, T val);     // Resizes the container so that it contains n elements. "val" is optional
		size_t	capacity() const;            // Return size of allocated storage capacity
		bool	empty() const;
		void	reserve(size_t n);           // Requests that the vector capacity be at least enough to contain n elements.

		/* Element access */
		T&			operator[](size_t n);		 // should never call this function with an argument n that is out of range ==> undefined behavior.
		const T&	operator[](size_t n) const;
		T&			at(size_t n);				 // throwing an out_of_range exception if it is not
		const T&	at(size_t n) const;
		T&			front();					 // Unlike member vector::begin, which returns an iterator to this same element, this function returns a direct reference.
		const T&	front() const;
		T&			back();
		const T&	back() const;
		T*			data() noexcept;			 // Returns pointer to the underlying array serving as element storage. a confirmer
		const T*	data() const noexcept;

		/* Modifiers */
		T			assign(Iterator first, Iterator last);	// Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
		void		assign(size_t n, const T& val);			// In the fill version (2), the new contents are n elements, each initialized to a copy of val.
		void 		push_back(const T& val);
		void		pop_back();
		iterator	insert(iterator/member_type position, const T& val);		 // inserting new elements before the element at the specified position
		void		insert(iterator/member_type position, size_type n, const value_type& val);   		// fill
		void		insert(iterator/member_type position, iterator first, iterator last);				// range
		iterator 	erase (iterator position);				    // erase single element
		iterator 	erase (iterator first, iterator last);		// erase range
		void		swap(vector& x);							// non-member function exists
		void		clear();		// Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.

		/* Allocator */
		T	get_allocator() const;

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