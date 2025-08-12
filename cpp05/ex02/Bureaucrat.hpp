#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>
#include "AForm.hpp"

class Form;

class Bureaucrat {

private:
	const	std::string _name;
	int		_grade;
	void	Bureaucrat::printExceptionMessage
				( std::string Message, AForm &form, char mode ) const;
public:
	Bureaucrat();
	Bureaucrat( std::string name, int grade );
	Bureaucrat( const Bureaucrat& other );
	~Bureaucrat();

	Bureaucrat& operator=( const Bureaucrat& other );

	void	signForm( AForm& form );
	void	executeForm( AForm& const form ) const;

	const std::string	getName() const;
	int					getGrade() const;

	void	incrementGrade();
	void	decrementGrade();

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Grade is too high!");
			}
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Grade is too low!");
			}
	};
} ;

std::ostream& operator<<(std::ostream&os, const Bureaucrat &bureaucrat);


#endif