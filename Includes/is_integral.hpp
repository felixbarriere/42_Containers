#pragma once

#include <iostream>
// #include <type_traits>


namespace ft
{
	template<typename T,T v>
	struct integral_constant
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_constant<T,v> type;
		
		value_type operator()(void) const { return value; }
		
		operator value_type() const { return value; }

		// operator T() { return v; }
	};

	typedef integral_constant<bool,true>  true_type;
  	typedef integral_constant<bool,false> false_type;

	template<typename T> struct is_integral:          	public	false_type{};
	template<> struct is_integral<bool>:              	public	true_type {};
	template<> struct is_integral<char>:              	public	true_type {};
	template<> struct is_integral<signed char>:			public	true_type {};
	template<> struct is_integral<unsigned char>:		public	true_type {};
	template<> struct is_integral<short>:             	public	true_type {};
	template<> struct is_integral<unsigned short>:    	public	true_type {};
	template<> struct is_integral<int>:               	public	true_type {};
	template<> struct is_integral<unsigned int>:      	public	true_type {};
	template<> struct is_integral<long>:              	public	true_type {};
	template<> struct is_integral<unsigned long>:     	public	true_type {};
	template<> struct is_integral<long long>:         	public	true_type {};
	template<> struct is_integral<unsigned long long>:	public	true_type {};
}