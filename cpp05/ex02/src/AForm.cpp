/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:38:49 by dioferre          #+#    #+#             */
/*   Updated: 2025/08/12 12:19:38 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("unknown"), _signGrade(150),
	_execGrade(150), _isSigned(false) {}

AForm::AForm( std::string name, int sign_grade, int exec_grade ) : _name(name), 
	_signGrade(sign_grade), _execGrade(exec_grade), _isSigned(false)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
}

AForm::AForm( const AForm& other ) : _name(other.getName()),
	_signGrade(other.getSignGrade()), _execGrade(other.getExecGrade()),
	_isSigned(other.getSignedStatus())
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

// =========== Overload Operators ===========

AForm& AForm::operator=( const AForm& other )
{
	if (this != &other)
	{
		_isSigned = other.getSignedStatus();
	}
	return (*this);
}

std::ostream& operator<<(std::ostream&os, const AForm &AForm)
{
	os << AForm.getName() << ", "
	<< "signed status: " << (AForm.getSignedStatus() ? "signed" : "unsigned") << ", "
	<< "minimum sign grade: " << AForm.getSignGrade() << ", "
	<< "minimum exec grade: " << AForm.getExecGrade() << ".";
	return (os);
}

// =========== Handle Signing ===========

void	AForm::beSigned( const Bureaucrat& bureaucrat )
{
	if (_isSigned)
		throw FormAlreadySignedException();
		
	if (bureaucrat.getGrade() > 0 && bureaucrat.getGrade() <= _signGrade)
		_isSigned = true;
	else if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	else
		throw GradeTooHighException();
}

void	AForm::execute( const Bureaucrat& executor ) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	
	if (executor.getGrade() > 0 && executor.getGrade() <= _execGrade)
		execForm();
	else if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	else
		throw GradeTooHighException();
}

// =========== Gettters ===========

const std::string AForm::getName() const
{
	return (_name);
}

int	AForm::getSignGrade() const
{
	return (_signGrade);
}

int	AForm::getExecGrade() const
{
	return (_execGrade);
}

bool	AForm::getSignedStatus() const
{
	return (_isSigned);
}