#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Colors.hpp"

#include <iostream>

class AForm;

class PresidentialPardonForm : public AForm {
private:
	std::string	_target;
protected:
	void execForm() const;
public:
	PresidentialPardonForm();
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( const PresidentialPardonForm& other );
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=( const PresidentialPardonForm& other );

	std::string	getTarget() const;
} ;

#endif