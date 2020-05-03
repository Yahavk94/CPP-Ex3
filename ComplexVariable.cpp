#include "Utils.hpp"
#include "ComplexVariable.hpp"

namespace solver {
	ComplexExpression operator + (ComplexExpression l1, ComplexExpression l2) {
		ComplexExpression l;
		l.a = l1.a + l2.a;
		l.b = l1.b + l2.b;
		l.c = l1.c + l2.c;

		if (l1.x != 0) l.x = l1.x; // l1.x = 0 or l2.x = 0 or l1.x = l2.x = 0
		else l.x = l2.x;
		return l;
	}

	ComplexExpression operator - (ComplexExpression l1, ComplexExpression l2) {
		ComplexExpression l;
		l.a = l1.a - l2.a;
		l.b = l1.b - l2.b;
		l.c = l1.c - l2.c;

		if (l1.x != 0) l.x = l1.x; // l1.x = 0 or l2.x = 0 or l1.x = l2.x = 0
		else l.x = l2.x;
		return l;
	}

	ComplexExpression operator * (ComplexExpression l1, ComplexExpression l2) {
		ComplexExpression l;
		l.a = l1.a * l2.c + l1.c * l2.a + l1.b * l2.b;
		l.b = l1.b * l2.c + l2.b * l1.c;
		l.c = l1.c * l2.c;

		if (l1.x != 0) l.x = l1.x; // l1.x = 0 or l2.x = 0
		else l.x = l2.x;
		return l;
	}

	ComplexExpression operator == (ComplexExpression l1, ComplexExpression l2) {
		ComplexExpression l = l1 - l2;
		if (l.a == std::complex<double>(0,0)) {
			if (l.b == std::complex<double>(0,0)) throw MyException("ERROR! can not divide by zero");
			l.x->comp = -l.c/l.b; // Linear form
			return l;
		}

		std::complex<double> determinant = l.b * l.b - std::complex<double>(4,0) * l.a * l.c; // Polynomial form
		l.x->comp = (-l.b - sqrt(determinant)) / (std::complex<double>(2,0) * l.a); // A single solution is required
		return l;
	}

	ComplexExpression operator + (ComplexExpression l1, std::complex<double> l2) {
		l1.c += l2;
		return l1;
	}

	ComplexExpression operator - (ComplexExpression l1, std::complex<double> l2) {
		l1.c -= l2;
		return l1;
	}

	ComplexExpression operator * (ComplexExpression l1, std::complex<double> l2) {
		l1.a *= l2;
		l1.b *= l2;
		l1.c *= l2;
		return l1;
	}

	ComplexExpression operator / (ComplexExpression l1, std::complex<double> l2) {
		if (l2 == std::complex<double>(0,0)) throw MyException("ERROR! can not divide by zero");
		l1.a /= l2;
		l1.b /= l2;
		l1.c /= l2;
		return l1;
	}

	ComplexExpression operator ^ (ComplexExpression l1, double l2) {
		if (l2 != 2) throw MyException("ERROR! this calculator is limited");
		ComplexExpression l;
		l.a = l1.b * l1.b;
		l.b = std::complex<double>(2,0) * l1.b * l1.c;
		l.c = l1.c * l1.c;
	
		l.x = l1.x;
		return l;
	}

	ComplexExpression operator == (ComplexExpression l1, std::complex<double> l2) {
		return l1 == ComplexExpression(l2);
	}

	ComplexExpression operator + (std::complex<double> l1, ComplexExpression l2) {
		l2.c += l1;
		return l2;
	}

	ComplexExpression operator - (std::complex<double> l1, ComplexExpression l2) {
		l2.c -= l1;
		return l2;
	}

	ComplexExpression operator * (std::complex<double> l1, ComplexExpression l2) {
		l2.a *= l1;
		l2.b *= l1;
		l2.c *= l1;
		return l2;
	}
}; // namespace solver

std::ostream& operator << (std::ostream& os, const std::complex<double> comp) {
	if (real(comp) == 0) os << '0'; // -0 display may occur
	else os << real(comp);
	if (imag(comp) == 0) return os << "+0i"; // +-0i display may occur
	if (imag(comp) > 0) return os << '+' << imag(comp) << 'i';
	return os << imag(comp) << 'i';
}