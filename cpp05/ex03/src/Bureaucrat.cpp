/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 09:33:44 by dioferre          #+#    #+#             */
/*   Updated: 2025/08/13 15:39:20 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150) {}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	
	_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : _name(other.getName()),
	_grade(other.getGrade()) {}

Bureaucrat::~Bureaucrat() {}

// =========== Overload Operators ===========

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other )
{
	if (this != &other)
	{
		_grade = other.getGrade();
	}
	return (*this);
}

std::ostream& operator<<(std::ostream&os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() 
	<< ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}

// =========== Form Handling ===========

void	Bureaucrat::printExceptionMessage( std::string Message, AForm const & form, char mode ) const
{
	std::string action;
	mode == 's' ? (action = "sign") : (action = "execute");
	
	std::cerr << getName() << " couldn't " << action << " "
	<< form.getName() << " beacause "<< Message << std::endl;
}

void	Bureaucrat::signForm( AForm& form )
{
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << "." << std::endl;
	} catch(const AForm::GradeTooLowException& e) {
		printExceptionMessage("its grade is too low.", form, 's');
	} catch(const AForm::FormAlreadySignedException& e) {
		printExceptionMessage("this form is already signed.", form, 's');
	} catch(const AForm::GradeTooHighException& e) {
		printExceptionMessage("its grade is too high (likely an invalid grade).",
			form, 's');
	}
}

void	Bureaucrat::executeForm( AForm const & form ) const
{
	try {
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << "." << std::endl;
	} catch(const AForm::FormNotSignedException& e) {
		printExceptionMessage("this form is not signed.", form, 'e');
	} catch(const AForm::GradeTooLowException) {
		printExceptionMessage("its grade is too low.", form, 'e');
	} catch(const AForm::GradeTooHighException& e) {
		printExceptionMessage("its grade is too high (likely an invalid grade).",
			 form, 'e');
	}
}

// =========== Others ===========

const std::string Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1) 
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150) 
		throw GradeTooLowException();
	_grade++;
}