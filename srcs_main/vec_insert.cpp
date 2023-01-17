#include "../tester_felix.hpp"
#include <vector>
#include "../Includes/vector.hpp"

void    insert_vector()
{
    std::cout << std::endl << " \e[0;33m************  Insert  ************\e[0m " << std::endl << std::endl;

    LIB::vector<int> test;

    test.insert(test.begin(), 3);
    test.push_back(4);
    test.push_back(5);
    test.push_back(6);
    test.push_back(7);
    test.insert(test.begin() + 1, 2);

    for (size_t i = 0; i < test.size(); i++)
    	std::cout << "test[i]= " << test[i] << std::endl;


    LIB::vector<int> test_insert(test.begin(), test.end() - 1);
    
    test_insert.insert(test_insert.begin(), test.begin(), test.begin() + 3);
    for (size_t i = 0; i < test_insert.size(); i++)
    	std::cout << "test_insert[i]= " << test_insert[i] << std::endl;

    LIB::vector<int> test3(test_insert.begin(), test_insert.end() - 1);

    test3.insert(test3.begin(), test3.begin(), test3.begin() + 4);

    for (size_t i = 0; i < test3.size(); i++)
    	std::cout << "test3[i]= " << test3[i] << std::endl;

    LIB::vector<int>::iterator first = test.begin();
    LIB::vector<int>::iterator last = test.end();
    LIB::vector<int> test4(first, last);

    LIB::vector<int> test_operator_equal = test4;

    std::cout << "test_operator_equal[0]= " << test_operator_equal[0] << std::endl;
}