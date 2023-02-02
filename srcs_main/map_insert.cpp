#include "../tester_felix.hpp"
#include <map>
#include "../Includes/map.hpp"

void insert_map()
{
	std::cout << std::endl << " \e[0;33m************  Insert  ************\e[0m " << std::endl << std::endl;
	
	LIB::map<int, std::string>test;
	
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

	std::cout << std::endl << " \e[0;33m************  Insert(hint)  ************\e[0m " << std::endl << std::endl;
	// LIB::map<int, std::string>test;
	// LIB::map<int, std::string>::iterator it;

	test.insert(it, LIB::pair<int, std::string>(3, "300"));

	it = test.begin();
	for (; it != test.end(); it++)
		std::cout  << "test[it]= " << it->first << " : "<< it->second << std::endl;

	LIB::map<int, std::string>test2;
	test2.insert( it, LIB::pair<int, std::string>(4, "400") );
	std::cout  << "test2[4]= " << test2[4] << std::endl;

	for (; it != test.end(); it++)
		std::cout  << "test[it]= " << it->first << " : "<< it->second << std::endl;

	std::cout << "test.size = " << test.size() << std::endl;
	it = test.begin();

	std::cout << std::endl << " \e[0;33m************  Insert(range)  ************\e[0m " << std::endl << std::endl;


	test2.insert( test.begin(), test.end());


	for (; it != test.end(); it++)
		std::cout  << "test[it]= " << it->first << " : "<< it->second << std::endl;


}