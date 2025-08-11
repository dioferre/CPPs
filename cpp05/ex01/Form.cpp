/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:38:49 by dioferre          #+#    #+#             */
/*   Updated: 2025/08/11 17:50:21 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("unknown"), _signGrade(150),
				_execGrade(150), _isSigned(false) {}

Form::Form( std::string name, int sign_grade, int exec_grade ) : _name(name), 
																_signGrade(sign_grade),
																_execGrade(exec_grade),
																_isSigned(false)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
}

Form::Form( const Form& other ) : _name(other.getName()),
									_signGrade(other.getSignGrade()),
									_execGrade(other.getExecGrade()),
									_isSigned(other.getSignedStatus())
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

// =========== Overload Operators ===========

Form& Form::operator=( const Form& other )
{
	if (this != &other)
	{
		_isSigned = other.getSignedStatus();
	}
	return (*this);
}

std::ostream& operator<<(std::ostream&os, const Form &Form)
{
	os << Form.getName() << ", "
	<< "signed status: " << (Form.getSignedStatus() ? "signed" : "unsigned") << ", "
	<< "minimum sign grade: " << Form.getSignGrade() << ", "
	<< "minimum exec grade: " << Form.getExecGrade() << ".";
	return (os);
}

// =========== Handle Signing ===========

void	Form::beSigned( const Bureaucrat& bureaucrat )
{
	if (_isSigned)
		throw -1;
		
	if (bureaucrat.getGrade() > 0 && bureaucrat.getGrade() <= _signGrade)
		_isSigned = true;
	else if (bureaucrat.getGrade() > 1)
		throw GradeTooLowException();
	else
		throw GradeTooHighException();
}

// =========== Gettters ===========

const std::string Form::getName() const
{
	return (_name);
}

int	Form::getSignGrade() const
{
	return (_signGrade);
}

int	Form::getExecGrade() const
{
	return (_execGrade);
}

bool	Form::getSignedStatus() const
{
	return (_isSigned);
}