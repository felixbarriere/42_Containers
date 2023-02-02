#include "../tester_felix.hpp"
#include <map>
#include "../Includes/map.hpp"

void erase_map()
{
	std::cout << std::endl << " \e[0;33m************  Erase  ************\e[0m " << std::endl << std::endl;

	LIB::map<int, std::string>test3;

	test3.insert( LIB::pair<int, std::string>(1, "100") );
	test3.insert( LIB::pair<int, std::string>(2, "200") );
	test3.insert( LIB::pair<int, std::string>(3, "300") );
	test3.insert( LIB::pair<int, std::string>(4, "400") );
	test3.insert( LIB::pair<int, std::string>(5, "500") );
	test3.insert( LIB::pair<int, std::string>(0, "600") );
	test3.erase(2);
	
	LIB::map<int, std::string>::iterator it;
	it = test3.begin();
	for (; it != test3.end(); it++)
		std::cout  << "test[it]= " << it->first << " : "<< it->second << std::endl;

	LIB::map<int, std::string>::iterator it3 = test3.upper_bound(3);
	test3.erase(it3);

	it = test3.begin();
	for (; it != test3.end(); it++)
		std::cout  << "test[it]= " << it->first << " : "<< it->second << std::endl;

}