#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {};
	MutantStack( const MutantStack& other ) : std::stack<T>(other) {};

	~MutantStack() {};

	MutantStack&	operator=( const MutantStack& other ) {
		if (this != &other)
			this->c = other.c;
		return (*this);
	};
	
	typedef typename std::stack<T>::container_type::iterator iterator; // Define iterator variable;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator; // Define iterator variable;

	// std::stack data is stored in a protected member 'c'	
	iterator		begin() { return (this->c.begin()); };
	iterator		end() { return (this->c.end()); };

	const_iterator		begin() const { return (this->c.begin()); };
	const_iterator		end() const { return (this->c.end()); };
} ;

#endif