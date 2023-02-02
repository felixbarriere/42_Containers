#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <map>
// #include <stack.hpp>
#include "Includes/vector.hpp"
#include "Includes/map.hpp"

#include "tester_felix.hpp"

int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
    std::cout << " \e[0;33m************  TEST VECTOR  ************\e[0m " << std::endl << std::endl;

	constructors_vector();
	assign_vector();
	pushpop_vector();
	resize_vector();
	insert_vector();
	modifiers_vector();

    std::cout << " \e[0;33m************  TEST MAP  ************\e[0m " << std::endl << std::endl;

	size_map();
	insert_map();
	bounds_map();
	erase_map();
	iterators_map();
}
