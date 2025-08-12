#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <fstream>
#include <iostream>

class AForm;

class ShrubberyCreationForm : public AForm {
private:
	const std::string	_target;
	void writeTree( std::ofstream& file ) const;
protected:
	void execForm() const;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( const ShrubberyCreationForm& other );
	~ShrubberyCreationForm();

	std::string	getTarget() const;
} ;

#endif