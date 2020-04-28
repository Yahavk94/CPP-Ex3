#pragma once

namespace solver {
	struct ComplexVariable {
		char roots = 0;
		std::complex<double> comp1;
		std::complex<double> comp2;
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

		ComplexExpression(int c) {
        	b = 0;
        	this->c = c;
        	x = 0;
    	}

		ComplexExpression(std::complex<double> c) {
        	b = 0;
			this->c = c;
        	x = 0;
    	}

    	ComplexExpression(ComplexVariable& comp) {
        	b = 1;
        	c = 0;
        	x = &comp;
    	}
	};

	ComplexExpression operator + (ComplexExpression l1, ComplexExpression l2);
	ComplexExpression operator - (ComplexExpression l1, ComplexExpression l2);
	ComplexExpression operator * (ComplexExpression l1, ComplexExpression l2);
	ComplexExpression operator / (ComplexExpression l1, ComplexExpression l2);
	ComplexExpression operator ^ (ComplexExpression l1, ComplexExpression l2);
	void operator == (ComplexExpression l1, ComplexExpression l2);
	std::ostream& operator << (std::ostream& os, const ComplexVariable& comp);
};