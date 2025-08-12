/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 09:33:44 by dioferre          #+#    #+#             */
/*   Updated: 2025/08/12 10:21:05 by dioferre         ###   ########.fr       */
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

void	Bureaucrat::printSignExceptions( std::string Message, Form &form ) const
{
	std::cerr << getName() << " couldn't sign " 
	<< form.getName() << " beacause "<< Message << std::endl;
}

void	Bureaucrat::signForm( Form& form )
{
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	} catch(const Form::GradeTooLowException& e) {
		printSignExceptions("its grade is too low.", form);
	} catch(const Form::GradeTooHighException& e) {
		printSignExceptions("its grade is too high (likely an invalid grade).", form);
	} catch(const Form::FormAlreadySignedException& e) {
		printSignExceptions("this form is already signed", form);
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