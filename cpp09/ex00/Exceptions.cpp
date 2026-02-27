#include "Exceptions.hpp"

InvalidColumnFormatException::InvalidColumnFormatException(const std::string& msg) : _message(msg) {}

InvalidColumnFormatException::~InvalidColumnFormatException() throw() {}

const char* InvalidColumnFormatException::what() const throw() {
    return _message.c_str();
}

CouldNotOpenFileException::CouldNotOpenFileException(const std::string& msg) : _message(msg) {}

CouldNotOpenFileException::~CouldNotOpenFileException() throw() {}

const char* CouldNotOpenFileException::what() const throw() {
    return _message.c_str();
}

const char* InvalidDateException::what() const throw() {
    return "";
}