#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <fstream>
#include <iostream>

class AForm;

class ShrubberyCreationForm : public AForm {
private:
	std::string	_target;
	void writeTree( std::ofstream& file ) const;
protected:
	void execForm() const;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( const ShrubberyCreationForm& other );
	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other );

	std::string	getTarget() const;
} ;

#endif