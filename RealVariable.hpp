#pragma once

namespace solver {
	struct RealVariable {
		double real;
	};

	struct RealExpression {
		double a = 0;
		double b;
		double c;
		struct RealVariable* x;

		RealExpression() {
			b = 0;
			c = 0;
		}

		RealExpression(double c) {
			b = 0;
			this->c = c;
			x = 0;
		}

		RealExpression(RealVariable& x) {
			b = 1;
			c = 0;
			this->x = &x;
		}
	};

	RealExpression operator + (RealExpression l1, RealExpression l2);
	RealExpression operator - (RealExpression l1, RealExpression l2);
	RealExpression operator * (RealExpression l1, RealExpression l2);
	RealExpression operator == (RealExpression l1, RealExpression l2);

	RealExpression operator + (RealExpression l1, double l2);
	RealExpression operator - (RealExpression l1, double l2);
	RealExpression operator * (RealExpression l1, double l2);
	RealExpression operator / (RealExpression l1, double l2);
	RealExpression operator ^ (RealExpression l1, double l2);
	RealExpression operator == (RealExpression l1, double l2);

	RealExpression operator + (double l1, RealExpression l2);
	RealExpression operator - (double l1, RealExpression l2);
	RealExpression operator * (double l1, RealExpression l2);
};