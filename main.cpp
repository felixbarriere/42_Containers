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
	
	constructors_vector();
	assign_vector();
	pushpop_vector();
	resize_vector();
	insert_vector();
	modifiers_vector();

	// LIB::map<int, std::string>test;

}