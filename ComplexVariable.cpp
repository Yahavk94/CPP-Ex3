#include "MyUtils.hpp"
#include "ComplexVariable.hpp"

using solver::ComplexVariable;
using solver::ComplexExpression;

ComplexExpression solver::operator + (ComplexExpression l1, ComplexExpression l2) {
	ComplexExpression l;
	l.a = l1.a + l2.a;
	l.b = l1.b + l2.b;
	l.c = l1.c + l2.c;

	if (l1.x != 0) l.x = l1.x; // l1.x = 0 or l2.x = 0 or l1.x = l2.x = 0
	else l.x = l2.x;
	return l;
}

ComplexExpression solver::operator - (ComplexExpression l1, ComplexExpression l2) {
	ComplexExpression l;
	l.a = l1.a - l2.a;
	l.b = l1.b - l2.b;
	l.c = l1.c - l2.c;

	if (l1.x != 0) l.x = l1.x; // l1.x = 0 or l2.x = 0 or l1.x = l2.x = 0
	else l.x = l2.x;
	return l;
}

ComplexExpression solver::operator * (ComplexExpression l1, ComplexExpression l2) {
	ComplexExpression l;
	l.a = l1.a * l2.c + l1.c * l2.a + l1.b * l2.b;
	l.b = l1.b * l2.c + l2.b * l1.c;
	l.c = l1.c * l2.c;

	if (l1.x != 0) l.x = l1.x; // l1.x = 0 or l2.x = 0
	else l.x = l2.x;
	return l;
}

ComplexExpression solver::operator / (ComplexExpression l1, ComplexExpression l2) {
	ComplexExpression l;
	if (l2.c == std::complex<double>(0,0)) throw MyException("ERROR! can not divide by zero");
	l.a = l1.a / l2.c;
	l.b = l1.b / l2.c;
	l.c = l1.c / l2.c;

	l.x = l1.x; // B.x = 0
	return l;
}

ComplexExpression solver::operator ^ (ComplexExpression l1, ComplexExpression l2) {
	ComplexExpression l;
	l.a = l1.b * l1.b;
	l.b = std::complex<double>(2,0) * l1.b * l1.c;
	l.c = l1.c * l1.c;

	l.x = l1.x;
	return l;
}

void solver::operator == (ComplexExpression l1, ComplexExpression l2) {
	ComplexExpression l = l1 - l2;
	if (l.a == std::complex<double>(0,0)) { // Linear form
		l.x->roots = 1;
		l.x->comp1 = -l.c/l.b;
	}

	else { // Polynomial form
		l.x->roots = 2;
		std::complex<double> determinant = l.b * l.b - std::complex<double>(4,0) * l.a * l.c;
		l.x->comp1 = (-l.b + sqrt(determinant)) / (std::complex<double>(2,0) * l.a);
		l.x->comp2 = (-l.b - sqrt(determinant)) / (std::complex<double>(2,0) * l.a);
	}
}

std::ostream& solver::operator << (std::ostream& os, const ComplexVariable& comp) {
	if (comp.roots < 2) {
		if (imag(comp.comp1) < 0) return os << real(comp.comp1) << '+' << imag(comp.comp1) << 'i';
		return os << real(comp.comp1) << imag(comp.comp1) << 'i';
	}

	if (imag(comp.comp1) < 0) os << real(comp.comp1) << imag(comp.comp1) << 'i' << " ";
	else os << real(comp.comp1) << '+' << imag(comp.comp1) << 'i' << " ";
	if (real(comp.comp2) == 0) os << "and" << " " << 0;
	else os << "and" << " " << real(comp.comp2);
	if (imag(comp.comp2) < 0) os << imag(comp.comp2) << 'i' << " ";
	else os << '+' << imag(comp.comp2) << 'i' << " ";

	return os;
}

int main() {
	ComplexVariable y;
	((5*y)^2) + 2 == y;
	std::cout << "y = " << y << std::endl;

	return 0;
}