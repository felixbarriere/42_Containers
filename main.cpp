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

	LIB::map<int, int>test;

	std::cout << "********************************** TEST MAIN **********************************" << std::endl;

	std::cout << test.size() << std::endl;


	test.insert( LIB::pair<int, int>(1, 100) );

	std::cout << test.size() << std::endl;

	// LIB::map<int, std::string>test2;
	// test2.insert( LIB::pair<int, std::string>(1, "test") );

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