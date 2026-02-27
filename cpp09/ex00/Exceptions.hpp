#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

class InvalidColumnFormatException : public std::exception {
private:
    std::string _message;
public:
    InvalidColumnFormatException(const std::string& msg);
    virtual ~InvalidColumnFormatException() throw();
    virtual const char* what() const throw();
};

class CouldNotOpenFileException : public std::exception {
private:
    std::string _message;
public:
    CouldNotOpenFileException(const std::string& msg);
    virtual ~CouldNotOpenFileException() throw();
    virtual const char* what() const throw();
};

class InvalidDateException : public std::exception {
public:
    virtual const char* what() const throw();
};

#endif