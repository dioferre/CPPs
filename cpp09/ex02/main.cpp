

#include <iostream>
#include <limits>
#include <vector>
#include <ctime>

#include "PmergeMe.hpp"

std::vector<unsigned int>	buildVector(char **argv)
{
	std::vector<unsigned int> v; 
	for (size_t i = 1; argv[i]; ++i)
	{
		long	value = atol(argv[i]);

		if (value <= 0) {
			throw std::invalid_argument("Non positive value.");
		} else if (value > __INT_MAX__) {
			throw std::invalid_argument("Too large a value.");
		}

		v.push_back(value);
	}
	return (v);
}

template <typename T>
void printContainer(const T& container) 
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Error: Too few arguments" << std::endl; 
		return (1);
	}

	std::vector<unsigned int> unsorted_v;

	try 
	{
		unsorted_v = buildVector(argv);

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (1);
	}

	std::vector<unsigned int> v = unsorted_v;
	double v_duration = -1;

	PmergeMe	mergeInsert;

	try
	{
		std::clock_t v_start = std::clock();
		mergeInsert.sort(v);
		std::clock_t v_end = std::clock();
		v_duration = static_cast<double>(v_end - v_start) / CLOCKS_PER_SEC * 1000000;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (1);
	}
/* 
	std::cout << "Before: ";
	printContainer(unsorted_v);

	std::cout << "\nAfter: ";
	printContainer(v);

 */
	std::cout << "Time to process a range of " << unsorted_v.size() << " elements with std::vector : "
		 << v_duration << " us" << std::endl;
	
	
	return (0);
}