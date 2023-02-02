#ifndef NULL_PTR_HPP
# define NULL_PTR_HPP

// NULL ne fonctionne pas

namespace ft
{
	const class nullptr_t
	{
		public:
			template<class T>
			operator T*() const { return 0; } 

			template<class C, class T>
			operator T C::*() const { return 0; }   

		private:
			void operator&() const;

	} null_ptr = {};  

};

#endif