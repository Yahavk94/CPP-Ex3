#include "MyUtils.hpp"
#include "RealVariable.hpp"

using solver::RealVariable;

RealVariable& solver::operator + (RealVariable& re1, RealVariable& re2) {
    return re1;
}

RealVariable& solver::operator + (RealVariable& re, double n) {
    return re;
}

RealVariable& solver::operator + (double n, RealVariable& re) {
    return re;
}

RealVariable& solver::operator - (RealVariable& re1, RealVariable& re2) {
    return re1;
}

RealVariable& solver::operator - (RealVariable& re, double n) {
    return re;
}

RealVariable& solver::operator - (double n, RealVariable& re) {
    return re;
}

RealVariable& solver::operator * (RealVariable& re1, RealVariable& re2) {
    return re1;
}

RealVariable& solver::operator * (RealVariable& re, double n) {
    return re;
}

RealVariable& solver::operator * (double n, RealVariable& re) {
    return re;
}

RealVariable& solver::operator / (RealVariable& re1, RealVariable& re2) {
    return re1;
}

RealVariable& solver::operator / (RealVariable& re, double n) {
    return re;
}

RealVariable& solver::operator / (double n, RealVariable& re) {
    return re;
}

RealVariable& solver::operator ^ (RealVariable& re, double n) {
    return re;
}

RealVariable& solver::operator == (RealVariable& re1, RealVariable& re2) {
    return re1;
}

RealVariable& solver::operator == (RealVariable& re, double n) {
    return re;
}