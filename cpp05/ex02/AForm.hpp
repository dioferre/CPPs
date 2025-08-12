#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const		std::string _name;
	const int	_signGrade;
	const int	_execGrade;
	bool		_isSigned;
protected:
	virtual void	execForm() const = 0;
public:
	AForm();
	AForm( std::string name, int sign_grade, int exec_grade );
	AForm( const AForm& other );
	~AForm();

	AForm& operator=( const AForm& other );

	void	beSigned( const Bureaucrat& bureaucrat );
	void	execute( const Bureaucrat& executor ) const ;


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

	class FormAlreadySignedException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Form is already signed!");
			}
	};

	class FormNotSignedException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Form not signed!");
			}
	};
} ;

std::ostream& operator<<(std::ostream&os, const AForm &bureaucrat);

#endif