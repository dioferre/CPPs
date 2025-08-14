#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "Colors.hpp"
#include "AForm.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

class AForm;

class RobotomyRequestForm : public AForm {
private:
	std::string	_target;
protected:
	void execForm() const;
public:
	RobotomyRequestForm();
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( const RobotomyRequestForm& other );
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=( const RobotomyRequestForm& other );

	std::string	getTarget() const;
} ;

#endif