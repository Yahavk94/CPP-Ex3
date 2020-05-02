#pragma once

#include <iostream>
#include <complex>

class MyException : public std::exception {
private:
    std::string msg;
public:
    MyException(std::string msg) {this->msg = msg;}
    ~MyException() {}
    virtual const char* what() const throw() {
        return msg.c_str();
    }
};