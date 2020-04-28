#include "MyUtils.hpp"
#include "RealVariable.hpp"

using solver::RealVariable;
using solver::RealLine;

RealLine solver::operator + (RealLine l1, RealLine l2) {
	RealLine l;
	l.a = l1.a + l2.a;
	l.b = l1.b + l2.b;
	l.c = l1.c + l2.c;

	if (l1.x != 0) l.x = l1.x; // l1.x = 0 or l2.x = 0 or l1.x = l2.x = 0
	else l.x = l2.x;
	return l;
}

RealLine solver::operator - (RealLine l1, RealLine l2) {
	RealLine l;
	l.a = l1.a - l2.a;
	l.b = l1.b - l2.b;
	l.c = l1.c - l2.c;

	if (l1.x != 0) l.x = l1.x; // l1.x = 0 or l2.x = 0 or l1.x = l2.x = 0
	else l.x = l2.x;
	return l;
}

RealLine solver::operator * (RealLine l1, RealLine l2) {
	RealLine l;
	l.a = l1.a * l2.c + l1.c * l2.a + l1.b * l2.b;
	l.b = l1.b * l2.c + l2.b * l1.c;
	l.c = l1.c * l2.c;

	if (l1.x != 0) l.x = l1.x; // l1.x = 0 or l2.x = 0
	else l.x = l2.x;
	return l;
}

RealLine solver::operator / (RealLine l1, RealLine l2) {
	RealLine l;
	if (l2.c == 0) throw MyException("ERROR! can not divide by zero");
	l.a = l1.a / l2.c;
	l.b = l1.b / l2.c;
	l.c = l1.c / l2.c;

	l.x = l1.x; // B.x = 0
	return l;
}

RealLine solver::operator ^ (RealLine l1, RealLine l2) {
	RealLine l;
	l.a = l1.b * l1.b;
	l.b = 2 * l1.b * l1.c;
	l.c = l1.c * l1.c;

	l.x = l1.x;
	return l;
}

void solver::operator == (RealLine l1, RealLine l2) {
	RealLine l = l1 - l2;
	if (l.a == 0) { // Linear form
		l.x->roots = 1;
		l.x->r1 = -l.c/l.b;
	}

	else { // Polynomial form
		double determinant = l.b * l.b - 4 * l.a * l.c;
		if (determinant < 0) throw MyException("ERROR! there is no real solution");
		l.x->r1 = (-l.b + sqrt(determinant)) / (2 * l.a);
		l.x->r2 = (-l.b - sqrt(determinant)) / (2 * l.a);
		if (l.x->r1 == l.x->r2) l.x->roots = 1; // Similar roots
		else l.x->roots = 2;
	}
}

std::ostream& solver::operator << (std::ostream& os, const RealVariable& real) {
	if (real.roots < 2) return os << real.r1;
    return os << real.r1 << " " << "or" << " " << real.r2;
}