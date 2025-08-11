#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat {

private:
	const	std::string _name;
	int		_grade;

public:
	Bureaucrat();
	Bureaucrat( std::string name, int grade );
	Bureaucrat( const Bureaucrat& other );
	~Bureaucrat();

	Bureaucrat& operator=( const Bureaucrat& other );

	const std::string	getName() const;
	int	getGrade() const;

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