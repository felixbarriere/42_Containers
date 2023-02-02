#include "../tester_felix.hpp"
#include <map>
#include "../Includes/map.hpp"

void size_map()
{
    std::cout << " \e[0;33m************  Size  ************\e[0m " << std::endl << std::endl;
        
	LIB::map<int, std::string>test;

	std::cout  << "test.max_size() = " << test.max_size() << std::endl;
	std::cout << "test.size()= " << test.size() << std::endl;
}