#include "../tester_felix.hpp"
#include <vector>
#include "../Includes/vector.hpp"

void    constructors_vector()
{
    std::cout << " \e[0;33m************  Constructors ************\e[0m " << std::endl << std::endl;

    LIB::vector<int> test;
    LIB::vector<int> test2(2, 98);
    std::cout << "test2[1]= " << test2[1] << std::endl;
    std::cout << "test2[5]= " << test2[5] << std::endl;  //should return invalid read

    LIB::vector<int> test3(test2.begin() + 1, test2.end());
    std::cout << "test3[0]= " << test3[0] << std::endl;
}