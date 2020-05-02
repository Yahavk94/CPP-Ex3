#pragma once

namespace solver {
	struct ComplexVariable {
		std::complex<double> comp;
	};
	
	struct ComplexExpression {
		std::complex<double> a = 0;
		std::complex<double> b;
		std::complex<double> c;
		struct ComplexVariable* x;

		ComplexExpression() {
			b = 0;
			c = 0;
		}

		ComplexExpression(std::complex<double> c) {
			b = 0;
			this->c = c;
			x = 0;
		}

		ComplexExpression(ComplexVariable& x) {
			b = 1;
			c = 0;
			this->x = &x;
		}
	};

	ComplexExpression operator + (ComplexExpression l1, ComplexExpression l2);
	ComplexExpression operator + (ComplexExpression l1, std::complex<double> l2);
	ComplexExpression operator + (std::complex<double> l1, ComplexExpression l2);

	ComplexExpression operator - (ComplexExpression l1, ComplexExpression l2);
	ComplexExpression operator - (ComplexExpression l1, std::complex<double> l2);
	ComplexExpression operator - (std::complex<double> l1, ComplexExpression l2);

	ComplexExpression operator * (ComplexExpression l1, ComplexExpression l2);
	ComplexExpression operator * (ComplexExpression l1, std::complex<double> l2);
	ComplexExpression operator * (std::complex<double> l1, ComplexExpression l2);

	ComplexExpression operator / (ComplexExpression l1, std::complex<double> l2);
	ComplexExpression operator ^ (ComplexExpression l1, double l2);
	
	ComplexExpression operator == (ComplexExpression l1, ComplexExpression l2);
	ComplexExpression operator == (ComplexExpression l1, std::complex<double> l2);
}; // namespace solver

std::ostream& operator << (std::ostream& os, const std::complex<double> comp);