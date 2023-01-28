#include <iostream>
#include <string>
#include <deque>
// #ifndef WHAT_LIB //CREATE A REAL STL EXAMPLE
	#include <vector>
	// #pragma message("STD")
	#include <map>
	// #include <stack>
	// namespace ft = std;
// #else
	#include "Includes/vector.hpp"
	#include "Includes/map.hpp"
// 	#include <stack.hpp>

#include "tester_felix.hpp"

int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	/* VECTOR */
	// constructors_vector();
	// assign_vector();
	// pushpop_vector();
	// resize_vector();
	// insert_vector();
	// modifiers_vector();

	/* MAP */


	LIB::map<int, std::string>test;
	test.insert( std::pair<char, std::string>('a', "test"));

	// std::cout << test['a'] << std::endl;
	// std::cout << "test.size = " << test.size() << std::endl;

	// std::cout << test[3] << std::endl;
	// std::cout << "test.size = " << test.size() << std::endl;

	// creer iterator
	// LIB::map<int, std::string>::iterator it = test.begin();

	// for (; it != test.end(); it++)
	// {
	// 	std::cout << it->first << std::endl;
	// 	std::cout << it->second << std::endl;
	// }

}