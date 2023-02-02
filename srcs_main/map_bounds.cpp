#include "../tester_felix.hpp"
#include <map>
#include "../Includes/map.hpp"

void bounds_map()
{
	std::cout << std::endl << " \e[0;33m************  Bounds  ************\e[0m " << std::endl << std::endl;


	LIB::map<int, std::string>test3;
	LIB::map<int, std::string>::iterator it;

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

}