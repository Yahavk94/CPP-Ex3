#include "Utils.hpp"
#include "RealVariable.hpp"

namespace solver {
	RealExpression operator + (RealExpression l1, RealExpression l2) {
		RealExpression l;
		l.a = l1.a + l2.a;
		l.b = l1.b + l2.b;
		l.c = l1.c + l2.c;

		if (l1.x != 0) l.x = l1.x; // l1.x = 0 or l2.x = 0 or l1.x = l2.x = 0
		else l.x = l2.x;
		return l;
	}

	RealExpression operator - (RealExpression l1, RealExpression l2) {
		RealExpression l;
		l.a = l1.a - l2.a;
		l.b = l1.b - l2.b;
		l.c = l1.c - l2.c;

		if (l1.x != 0) l.x = l1.x; // l1.x = 0 or l2.x = 0 or l1.x = l2.x = 0
		else l.x = l2.x;
		return l;
	}

	RealExpression operator * (RealExpression l1, RealExpression l2) {
		RealExpression l;
		l.a = l1.a * l2.c + l1.c * l2.a + l1.b * l2.b;
		l.b = l1.b * l2.c + l2.b * l1.c;
		l.c = l1.c * l2.c;

		if (l1.x != 0) l.x = l1.x; // l1.x = 0 or l2.x = 0
		else l.x = l2.x;
		return l;
	}

	RealExpression operator == (RealExpression l1, RealExpression l2) {
		RealExpression l = l1 - l2;
		if (l.a == 0) {
			if (l.b == 0) throw MyException("ERROR! can not divide by zero");
			l.x->real = -l.c/l.b; // Linear form
			return l;
		}

		double determinant = l.b * l.b - 4 * l.a * l.c; // Polynomial form
		if (determinant < 0) throw MyException("ERROR! there is no real solution");
		l.x->real = (-l.b + sqrt(determinant)) / (2 * l.a); // A single solution is required
		return l;
	}

	RealExpression operator + (RealExpression l1, double l2) {
		l1.c += l2;
		return l1;
	}

	RealExpression operator - (RealExpression l1, double l2) {
		l1.c -= l2;
		return l1;
	}

	RealExpression operator * (RealExpression l1, double l2) {
		l1.a *= l2;
		l1.b *= l2;
		l1.c *= l2;
		return l1;
	}

	RealExpression operator / (RealExpression l1, double l2) {
		if (l2 == 0) throw MyException("ERROR! can not divide by zero");
		l1.a /= l2;
		l1.b /= l2;
		l1.c /= l2;
		return l1;
	}

	RealExpression operator ^ (RealExpression l1, double l2) {
		if (l2 != 2) throw MyException("ERROR! this calculator is limited");
		RealExpression l;
		l.a = l1.b * l1.b;
		l.b = 2 * l1.b * l1.c;
		l.c = l1.c * l1.c;

		l.x = l1.x; // l2.x = 0
		return l;
	}

	RealExpression operator == (RealExpression l1, double l2) {
		return l1 == RealExpression(l2);
	}

	RealExpression operator + (double l1, RealExpression l2) {
		l2.c += l1;
		return l2;
	}

	RealExpression operator - (double l1, RealExpression l2) {
		l2.c -= l1;
		return l2;
	}

	RealExpression operator * (double l1, RealExpression l2) {
		l2.a *= l1;
		l2.b *= l1;
		l2.c *= l1;
		return l2;
	}
}; // namespace solver