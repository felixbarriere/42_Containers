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

	std::cout << "********************************** TEST MAIN **********************************" << std::endl;

	LIB::map<int, std::string>test;

	std::cout  << "test.max_size() = " << test.max_size() << std::endl;

	std::cout << "test.size()= " << test.size() << std::endl;

	std::cout << std::endl << " **************** insert **************** " << std::endl << std::endl;
	
	test.insert( LIB::pair<int, std::string>(1, "100") );
	test.insert( LIB::pair<int, std::string>(2, "200") );

	std::cout << "test.size= " << test.size() << std::endl;

	LIB::map<int, std::string>::iterator it;
	it = test.begin();

	for (; it != test.end(); it++)
		std::cout  << "test[it]= " << it->first << " : "<< it->second << std::endl;

	std::cout  << "test[2]= " << test[2] << std::endl;
	std::cout  << "test[0]= " << test[0] << std::endl;

	test.insert( LIB::pair<int, std::string>(5, "500") );

	for (; it != test.end(); it++)
		std::cout  << "test[it]= " << it->first << " : "<< it->second << std::endl;

	it = test.begin();

	std::cout << std::endl << " **************** insert (hint) **************** " << std::endl << std::endl;

	test.insert(it, LIB::pair<int, std::string>(3, "300"));

	for (; it != test.end(); it++)
		std::cout  << "test[it]= " << it->first << " : "<< it->second << std::endl;

	LIB::map<int, std::string>test2;
	test2.insert( it, LIB::pair<int, std::string>(4, "400") );
	std::cout  << "test2[4]= " << test2[4] << std::endl;

	for (; it != test.end(); it++)
		std::cout  << "test[it]= " << it->first << " : "<< it->second << std::endl;

	std::cout << "test.size = " << test.size() << std::endl;
	it = test.begin();

	std::cout << std::endl << " **************** insert (range) **************** " << std::endl << std::endl;

	test2.insert( test.begin(), test.end());


	for (; it != test.end(); it++)
		std::cout  << "test[it]= " << it->first << " : "<< it->second << std::endl;

	// it = test3.begin();

	std::cout << std::endl << " **************** Bounds **************** " << std::endl << std::endl;

	LIB::map<int, std::string>test3;

	test3.insert( LIB::pair<int, std::string>(1, "100") );
	test3.insert( LIB::pair<int, std::string>(2, "200") );
	test3.insert( LIB::pair<int, std::string>(3, "300") );
	test3.insert( LIB::pair<int, std::string>(4, "400") );
	test3.insert( LIB::pair<int, std::string>(5, "500") );
	test3.insert( LIB::pair<int, std::string>(0, "600") );

	// test3.printTree();
	std::cout << std::endl << std::endl;

	LIB::map<int, std::string>::iterator it2;
	LIB::map<int, std::string>::iterator it3;

	it2 = test3.lower_bound(3);
	it3 = test3.upper_bound(3);

	std::cout  << "it2->first= " << it2->first << std::endl;
	std::cout  << "it3->first= " << it3->first << std::endl;

	std::cout << std::endl << " **************** Erase **************** " << std::endl << std::endl;

	test3.erase(2);
	
	it = test3.begin();
	for (; it != test3.end(); it++)
		std::cout  << "test[it]= " << it->first << " : "<< it->second << std::endl;

	test3.erase(it3);

	it = test3.begin();
	for (; it != test3.end(); it++)
		std::cout  << "test[it]= " << it->first << " : "<< it->second << std::endl;
}
