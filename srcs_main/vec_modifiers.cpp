#include "../tester_felix.hpp"
#include <vector>
#include "../Includes/vector.hpp"

void    modifiers_vector()
{
    std::cout << std::endl << " \e[0;33m************  Modifiers  ************\e[0m " << std::endl << std::endl;

    LIB::vector<int> test(2, 98);
    LIB::vector<int>::iterator first = test.begin();
    LIB::vector<int>::iterator last = test.end();
    LIB::vector<int> test4(first, last);

    LIB::vector<int> test_operator_equal = test4;

    std::cout << "test_operator_equal[2]= " << test_operator_equal[1] << std::endl;


    test_operator_equal.push_back(42);
    std::cout << "PUSH_BACK: test_operator_equal[2]= " << test_operator_equal[2] << std::endl;

    test_operator_equal.clear();

    test_operator_equal.push_back(43);
    test_operator_equal.push_back(43);
    std::cout << "CLEAR: test_operator_equal[2]= " << test_operator_equal[2] << std::endl;
    test_operator_equal.push_back(43);
    std::cout << "CLEAR: test_operator_equal[2]= " << test_operator_equal[2] << std::endl;

    std::cout << "test_operator_equal.front()= " << test_operator_equal.front() << std::endl;
    std::cout << "test_operator_equal.back()= " << test_operator_equal.back() << std::endl;
    std::cout << "test_operator_equal.size()= " << test_operator_equal.size() << std::endl;

    test_operator_equal.push_back(4);
    test_operator_equal.push_back(4);
    test_operator_equal.push_back(4);

    test_operator_equal.pop_back();
    std::cout << "test_operator_equal.front()= " << test_operator_equal.front() << std::endl;
    std::cout << "POP_BACK: test_operator_equal.back()= " << test_operator_equal.back() << std::endl;
    std::cout << "POP_BACK: test_operator_equal.size()= " << test_operator_equal.size() << std::endl;
}