#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>

class InvalidColumnFormatException : public std::exception{
private:
	std::string message;
public:
    virtual const char* what() const throw(){ return (this->message.c_str()); }

    InvalidColumnFormatException(const std::string& msg){ this->message = msg; }
	~InvalidColumnFormatException() throw(){}
};

class CouldNotOpenFileException : public std::exception{
private:
	std::string message;
public:
    virtual const char* what() const throw(){ return (this->message.c_str()); }

    CouldNotOpenFileException(const std::string& msg){ this->message = msg; }
	~CouldNotOpenFileException() throw(){}
};

#endif