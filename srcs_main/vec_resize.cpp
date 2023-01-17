#include "../tester_felix.hpp"
#include <vector>
#include "../Includes/vector.hpp"

void    resize_vector()
{
        std::cout << " \e[0;33m************  Resize  ************\e[0m " << std::endl << std::endl;

		LIB::vector<int> vct(2);
        LIB::vector<std::string> vct2;
        LIB::vector<int> test2(2, 98);

		for (size_t i = 0; i < vct.size(); i++)
			std::cout << "vct[i]= " << vct[i] << std::endl;
		std::cout << "vct.size()= " << vct.size() << std::endl;
		vct.resize(5);
		std::cout << "Resize" << std::endl;

		for (size_t i = 0; i < vct.size(); i++)
			std::cout << "vct[i]= " << vct[i] << std::endl;
		std::cout << "vct.size()= " << vct.size() << std::endl;

		vct[2] = 42;
		std::cout << "vct[2]= " << vct[2] << std::endl;

		for (size_t i = 0; i < vct.size(); i++)
			std::cout << "vct[i]= " << vct[i] << std::endl;

		LIB::vector<int>::iterator first = test2.begin();
		LIB::vector<int>::iterator last = test2.end();

		LIB::vector<int> test4(first, last);

		std::cout << "test4[0]= " << test4[0] << std::endl;
		std::cout << "test4.at(1)= " << test4.at(1) << std::endl;
		// std::cout << "test4.at(5)= " << test4.at(5) << std::endl;	    //should send exception
		// std::cout << "test4.at(90)= " << test4.at(90) << std::endl;      //should send exception
		// std::cout << "test4.at(-90)= " << test4.at(-90) << std::endl;    //should send exception

		LIB::vector<int> test_copy(test4);
		std::cout << "test_copy[0]= " << test_copy[0] << std::endl;
}