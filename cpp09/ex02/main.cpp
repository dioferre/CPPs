#include <iostream>
#include <limits>
#include <deque>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdexcept>
#include "PmergeMe.hpp"

const bool SHORTEN_SEQUENCE_PRINT = true;
const int MAX_PRINT_ELEMENTS = 10;

template <typename T>
void printContainer(const T& container) 
{
	if (SHORTEN_SEQUENCE_PRINT) {
		int count = 0;
		for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
			std::cout << *it << " ";
			if (++count >= MAX_PRINT_ELEMENTS) {
				std::cout << "[...]";
				break;
			}
		}
	} else {
		for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
			std::cout << *it << " ";
		}
	}
	std::cout << std::endl;
}

template <typename T>
bool isSorted(const T& container)
{
	if (container.empty())
		return true;
	
	typename T::const_iterator current = container.begin();
	typename T::const_iterator next = current;
	++next;
	
	while (next != container.end()) {
		if (*current > *next)
			return false;
		++current;
		++next;
	}
	return true;
}

void checkArgs(int argc, char **argv, 
			   std::vector<unsigned int>& v, 
			   std::deque<unsigned int>& d)
{
	if (argc < 2) {
		throw std::invalid_argument("Too few arguments.");
	}
	
	for (int i = 1; i < argc; ++i) {
		char *endptr;
		long value = std::strtol(argv[i], &endptr, 10);
		
		if (*endptr != '\0') {
			throw std::invalid_argument("Invalid number format.");
		}
		if (value <= 0) {
			throw std::invalid_argument("Non positive value.");
		}
		if (value > __INT_MAX__) {
			throw std::invalid_argument("Too large a value.");
		}
		
		v.push_back(static_cast<unsigned int>(value));
		d.push_back(static_cast<unsigned int>(value));
	}
}

int main(int argc, char **argv)
{
	std::vector<unsigned int> unsorted_v;
	std::deque<unsigned int> d;
	
	try {
		checkArgs(argc, argv, unsorted_v, d);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
		return 1;
	}
	
	std::vector<unsigned int> v = unsorted_v;
	PmergeMe mergeInsert;
	
	try {
		std::clock_t v_start = std::clock();
		mergeInsert.sort(v);
		std::clock_t v_end = std::clock();
		double v_duration = static_cast<double>(v_end - v_start) / CLOCKS_PER_SEC * 1000000;
		
		std::clock_t d_start = std::clock();
		mergeInsert.sort(d);
		std::clock_t d_end = std::clock();
		double d_duration = static_cast<double>(d_end - d_start) / CLOCKS_PER_SEC * 1000000;
		
		if (!isSorted(v)) {
			throw std::logic_error("Vector sorting failed.");
		}
		if (!isSorted(d)) {
			throw std::logic_error("Deque sorting failed.");
		}
		
		std::cout << "Before: ";
		printContainer(unsorted_v);
		std::cout << "\nAfter:  ";
		printContainer(v);
		std::cout << "Time to process a range of " << unsorted_v.size() 
				  << " elements with std::vector : " << v_duration << " us" << std::endl;
		std::cout << "Time to process a range of " << unsorted_v.size() 
				  << " elements with std::deque  : " << d_duration << " us" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
		return 1;
	}
	
	return 0;
}