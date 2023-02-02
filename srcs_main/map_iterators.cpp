#include "../tester_felix.hpp"
#include <map>
#include "../Includes/map.hpp"

void iterators_map()
{
	std::cout << std::endl << " \e[0;33m************  Iterators  ************\e[0m " << std::endl << std::endl;

	LIB::map<int, std::string>test3;

	test3.insert( LIB::pair<int, std::string>(1, "100") );
	test3.insert( LIB::pair<int, std::string>(2, "200") );
	test3.insert( LIB::pair<int, std::string>(3, "300") );
	test3.insert( LIB::pair<int, std::string>(4, "400") );
	test3.insert( LIB::pair<int, std::string>(5, "500") );
	test3.insert( LIB::pair<int, std::string>(0, "600") );

	LIB::map<int, std::string>::iterator it4(test3.begin());
	LIB::map<int, std::string>::iterator it5(test3.begin());

	std::cout  << "it4= " << it4->first << " : "<< it4->second << std::endl;
	std::cout  << "it5= " << it5->first << " : "<< it5->second << std::endl;

	std::cout  << "it4++= " << it4++->first << " : "<< it4++->second << std::endl;
	std::cout  << "it5++= " << it5++->first << " : "<< it5++->second << std::endl;

	std::cout  << "it4++= " << it4++->first << " : "<< it4++->second << std::endl;
	std::cout  << "it5++= " << it5++->first << " : "<< it5++->second << std::endl;


}