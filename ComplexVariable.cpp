#include "MyUtils.hpp"
#include "ComplexVariable.hpp"

using solver::ComplexVariable;

ComplexVariable& solver::operator + (ComplexVariable& comp1, ComplexVariable& comp2) {
    return comp1;
}

ComplexVariable& solver::operator + (ComplexVariable& comp, double n) {
    return comp;
}

ComplexVariable& solver::operator + (double n, ComplexVariable& comp) {
    return comp;
}

ComplexVariable& solver::operator + (ComplexVariable& comp1, std::complex<double> comp2) {
    return comp1;
}

ComplexVariable& solver::operator + (std::complex<double> comp2, ComplexVariable& comp1) {
    return comp1;
}

ComplexVariable& solver::operator - (ComplexVariable& comp1, ComplexVariable& comp2) {
    return comp1;
}

ComplexVariable& solver::operator - (ComplexVariable& comp, double n) {
    return comp;
}

ComplexVariable& solver::operator - (double n, ComplexVariable& comp) {
    return comp;
}

ComplexVariable& solver::operator - (ComplexVariable& comp1, std::complex<double> comp2) {
    return comp1;
}

ComplexVariable& solver::operator - (std::complex<double> comp2, ComplexVariable& comp1) {
    return comp1;
}

ComplexVariable& solver::operator * (ComplexVariable& comp1, ComplexVariable& comp2) {
    return comp1;
}

ComplexVariable& solver::operator * (ComplexVariable& comp, double n) {
    return comp;
}

ComplexVariable& solver::operator * (double n, ComplexVariable& comp) {
    return comp;
}

ComplexVariable& solver::operator * (ComplexVariable& comp1, std::complex<double> comp2) {
    return comp1;
}

ComplexVariable& solver::operator * (std::complex<double> comp2, ComplexVariable& comp1) {
    return comp1;
}
        
ComplexVariable& solver::operator / (ComplexVariable& comp1, ComplexVariable& comp2) {
    return comp1;
}

ComplexVariable& solver::operator / (ComplexVariable& comp, double n) {
    return comp;
}

ComplexVariable& solver::operator / (double n, ComplexVariable& comp) {
    return comp;
}

ComplexVariable& solver::operator / (ComplexVariable& comp1, std::complex<double> comp2) {
    return comp1;
}

ComplexVariable& solver::operator / (std::complex<double> comp2, ComplexVariable& comp1) {
    return comp1;
}
        
ComplexVariable& solver::operator ^ (ComplexVariable& comp, double n) {
    return comp;
}

ComplexVariable& solver::operator == (ComplexVariable& comp1, ComplexVariable& comp2) {
    return comp1;
}

ComplexVariable& solver::operator == (ComplexVariable& comp, double n) {
    return comp;
}

ComplexVariable& solver::operator == (ComplexVariable& comp1, std::complex<double> comp2) {
    return comp1;
}