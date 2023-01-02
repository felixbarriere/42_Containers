#include <iostream>
#include <string>
// #include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
	// #include <map>
	// #include <stack>
	#include <vector>
	// namespace ft = std;
// #else
// 	#include <map.hpp>
// 	#include <stack.hpp>
#include "Includes/vector.hpp"

// #endif

// #include <stdlib.h>

/* ****************************************  MAIN PERSO **************************************************** */


int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;
	{
		std::cout << std::endl << " \e[0;33m************  FT  ************\e[0m " << std::endl << std::endl;
		
		/* Constructors */
		std::cout << " \e[0;33m************  Constructors  ************\e[0m " << std::endl << std::endl;

		ft::vector<int> test;
		ft::vector<int> test2(2, 98);
		std::cout << "test2[1]= " << test2[1] << std::endl;
		// std::cout << "test2[5]= " << test2[5] << std::endl;  //should return invalid read

		ft::vector<int> test3(test2.begin() + 1, test2.end());
		std::cout << "test3[0]= " << test3[0] << std::endl;

		ft::vector<int>::iterator first = test2.begin();
		ft::vector<int>::iterator last = test2.end();

		ft::vector<int> test4(first, last);
		std::cout << "test4[0]= " << test4[0] << std::endl;
		std::cout << "test4.at(1)= " << test4.at(1) << std::endl;
		// std::cout << "test4.at(5)= " << test4.at(5) << std::endl;	//should send exception
		// std::cout << "test4.at(90)= " << test4.at(90) << std::endl;
		// std::cout << "test4.at(-90)= " << test4.at(-90) << std::endl;

		ft::vector<int> test_copy(test4);
		std::cout << "test_copy[0]= " << test_copy[0] << std::endl;


		ft::vector<int> test_operator_equal = test4;
		std::cout << "test_operator_equal[0]= " << test_operator_equal[0] << std::endl;

		std::cout << std::endl << " \e[0;33m************  Modifiers  ************\e[0m " << std::endl << std::endl;

		test_operator_equal.push_back(42);
		std::cout << "PUSH_BACK: test_operator_equal[2]= " << test_operator_equal[2] << std::endl;

		// test_operator_equal.clear();
		// std::cout << "Clear: test_operator_equal[2]= " << test_operator_equal[2] << std::endl;

		std::cout << "test_operator_equal.front()= " << test_operator_equal.front() << std::endl;
		std::cout << "test_operator_equal.back()= " << test_operator_equal.back() << std::endl;
		std::cout << "test_operator_equal.size()= " << test_operator_equal.size() << std::endl;


		test_operator_equal.pop_back();
		std::cout << "POP_BACK: test_operator_equal.back()= " << test_operator_equal.back() << std::endl;
		std::cout << "POP_BACK: test_operator_equal.size()= " << test_operator_equal.size() << std::endl;

		std::cout << std::endl << " \e[0;33m************  RESIZE  ************\e[0m " << std::endl << std::endl;

		test_operator_equal.resize(1);
		std::cout << "RESIZE(1): test_operator_equal.size()= " << test_operator_equal.size() << std::endl;
		test_operator_equal.resize(5);
		std::cout << "RESIZE(5): test_operator_equal.size()= " << test_operator_equal.size() << std::endl;
		test_operator_equal.resize(125);
		std::cout << "RESIZE(125): test_operator_equal.size()= " << test_operator_equal.size() << std::endl;
	}

	/* **************************** STD ********************************** */
	{
		std::cout << std::endl << " \e[0;33m************  STD  ************\e[0m " << std::endl << std::endl;

		/* Constructors */
		std::cout << " \e[0;33m************  Constructors  ************\e[0m " << std::endl << std::endl;

		std::vector<int> test;
		std::vector<int> test2(2, 98);
		std::cout << "test2[1]= " << test2[1] << std::endl;
		// std::cout << "test2[5]= " << test2[5] << std::endl;	//should return invalid read

		std::vector<int> test3(test2.begin() + 1, test2.end());
		std::cout << "test3[0]= " << test3[0] << std::endl;

		std::vector<int>::iterator first = test2.begin();
		std::vector<int>::iterator last = test2.end();

		std::vector<int> test4(first, last);
		std::cout << "test4[0]= " << test4[0] << std::endl;
		std::cout << "test4.at(1)= " << test4.at(1) << std::endl;
		// std::cout << "test4.at(5)= " << test4.at(5) << std::endl;	//should send exception
		// std::cout << "test4.at(90)= " << test4.at(90) << std::endl;
		// std::cout << "test4.at(-90)= " << test4.at(-90) << std::endl;		

		std::vector<int> test_copy(test4);
		std::cout << "test_copy[0]= " << test_copy[0] << std::endl;


		std::vector<int> test_operator_equal = test4;
		std::cout << "test_operator_equal[0]= " << test_operator_equal[0] << std::endl;

		std::cout << std::endl << " \e[0;33m************  Modifiers  ************\e[0m " << std::endl << std::endl;

		test_operator_equal.push_back(42);
		std::cout << "PUSH_BACK: test_operator_equal[2]= " << test_operator_equal[2] << std::endl;

		test_operator_equal.clear();
		std::cout << "Clear: test_operator_equal[2]= " << test_operator_equal[2] << std::endl;

		std::cout << "test_operator_equal.front()= " << test_operator_equal.front() << std::endl;
		std::cout << "test_operator_equal.back()= " << test_operator_equal.back() << std::endl;
		std::cout << "test_operator_equal.size()= " << test_operator_equal.size() << std::endl;

		test_operator_equal.pop_back();
		std::cout << "POP_BACK: test_operator_equal.back()= " << test_operator_equal.back() << std::endl;
		std::cout << "POP_BACK: test_operator_equal.size()= " << test_operator_equal.size() << std::endl;

		std::cout << std::endl << " \e[0;33m************  RESIZE  ************\e[0m " << std::endl << std::endl;

		test_operator_equal.resize(1);
		std::cout << "RESIZE(1): test_operator_equal.size()= " << test_operator_equal.size() << std::endl;
		test_operator_equal.resize(5);
		std::cout << "RESIZE(5): test_operator_equal.size()= " << test_operator_equal.size() << std::endl;
		test_operator_equal.resize(125);
		std::cout << "RESIZE(125): test_operator_equal.size()= " << test_operator_equal.size() << std::endl;

	}
	return (0);
}











/* ****************************************  MAIN INTRA **************************************************** */

// #define MAX_RAM 42949
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

	// ft::vector<std::string> vector_str;
	// ft::vector<int> vector_int;
	// ft::stack<int> stack_int;
	// ft::vector<Buffer> vector_buffer;
	// ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	// ft::map<int, int> map_int;

	// for (int i = 0; i < COUNT; i++)
	// {
	// 	vector_buffer.push_back(Buffer());
	// }

	// std::cout << "vector_buffer.size(): " << vector_buffer.size() << std::endl;
	// for (int i = 0; i < COUNT; i++)
	// {
	// 	const int idx = rand() % COUNT;
	// 	vector_buffer[idx].idx = 5;
	// 	std::cout << "vector_buffer[i]: " << vector_buffer[i].idx << std::endl;
	// }


	// ft::vector<Buffer>().swap(vector_buffer);

	// try
	// {
	// 	for (int i = 0; i < COUNT; i++)
	// 	{
	// 		const int idx = rand() % COUNT;
	// 		vector_buffer.at(idx);
	// 		std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
	// 	}
	// }
	// catch(const std::exception& e)
	// {
	// 	//NORMAL ! :P
	// 	std::cerr << "Vector is empty" <<std::endl;
	// }
	
	// for (int i = 0; i < COUNT; ++i)
	// {
	// 	map_int.insert(ft::make_pair(rand(), rand()));
	// }

	// int sum = 0;
	// for (int i = 0; i < 10000; i++)
	// {
	// 	int access = rand();
	// 	sum += map_int[access];
	// }
	// std::cout << "should be constant with the same seed: " << sum << std::endl;

	// {
	// 	ft::map<int, int> copy = map_int;
	// }
	// MutantStack<char> iterable_stack;
	// for (char letter = 'a'; letter <= 'z'; letter++)
	// 	iterable_stack.push(letter);
	// for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	// {
	// 	std::cout << *it;
	// }
// 	std::cout << std::endl;
// 	return (0);
// }