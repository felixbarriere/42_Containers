#include "../tester_felix.hpp"
#include <vector>
#include "../Includes/vector.hpp"

void    pushpop_vector()
{
    std::cout << " \e[0;33m************  Push Pop  ************\e[0m " << std::endl << std::endl;
    
    LIB::vector<int> test;

    test.push_back(11);
    test.push_back(34);
    test.push_back(23);
    for (size_t i = 0; i < test.size(); i++)
        std::cout << "test[i]= " << test[i] << std::endl;
    test.pop_back();
    std::cout << "Pop_back" << std::endl;
    std::cout << "test[last]= " << test[test.size()] << std::endl;
    test.pop_back();
    std::cout << "Pop_back" << std::endl;
    std::cout << "test[last]= " << test[test.size()] << std::endl;

    std::cout << "Strings" << std::endl;

    LIB::vector<std::string> vct(8);
    LIB::vector<std::string> vct2;

    vct.push_back("One long string");
    vct2.push_back("Another long string");
    
    std::cout << "vct[8]= " << vct[8] << std::endl;
    std::cout << "vct2[0]= " << vct2[0] << std::endl;
}