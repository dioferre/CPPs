#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:
	const		std::string _name;
	const int	_signGrade;
	const int	_execGrade;
	bool		_isSigned;

public:
	Form();
	Form( std::string name, int sign_grade, int exec_grade );
	Form( const Form& other );
	~Form();

	Form& operator=( const Form& other );

	void	beSigned( const Bureaucrat& bureaucrat );

	const std::string	getName() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	bool				getSignedStatus() const;

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

std::ostream& operator<<(std::ostream&os, const Form &bureaucrat);

#endif