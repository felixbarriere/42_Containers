#include "../tester_felix.hpp"
#include <vector>
#include "../Includes/vector.hpp"

void assign_vector()
{
    std::cout << " \e[0;33m************  Assign  ************\e[0m " << std::endl << std::endl;
        
    LIB::vector<int> test;
    LIB::vector<int> test2(2, 98);

    test2.push_back(103);
    test2.push_back(104);
    test2.push_back(105);
    test.assign(test2.begin() + 1, test2.end());
    std::cout << "test[2]= " << test[2] << std::endl;
    std::cout << "test[3]= " << test[3] << std::endl;
}