#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <map>
#include <exception>

class AForm;

class Intern
{
private:

	typedef AForm* (Intern::*CreateFunc)(std::string&) const;

	AForm*	makePresidential( std::string& target ) const;
	AForm*	makeRobotomy( std::string& target ) const;
	AForm*	makeShrubbery( std::string& target ) const;
public:
	Intern();
	Intern( const Intern& other );
	~Intern();

	Intern&	operator=( const Intern& other );

	AForm*	makeForm( std::string form_name, std::string form_target );
};

#endif