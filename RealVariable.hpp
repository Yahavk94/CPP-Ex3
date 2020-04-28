#pragma once

namespace solver {
	struct RealVariable {
		char roots = 0;
		double r1;
		double r2;
	};

	struct RealLine {
		double a = 0;
    	double b;
		double c;
		struct RealVariable* x;

		RealLine() {
			b = 0;
			c = 0;
		}

		RealLine(int c) {
        	b = 0;
        	this->c = c;
        	x = 0;
    	}

    	RealLine(RealVariable& real) {
        	b = 1;
        	c = 0;
        	x = &real;
    	}
	};

	RealLine operator + (RealLine l1, RealLine l2);
	RealLine operator - (RealLine l1, RealLine l2);
	RealLine operator * (RealLine l1, RealLine l2);
	RealLine operator / (RealLine l1, RealLine l2);
	RealLine operator ^ (RealLine l1, RealLine l2);
	void operator == (RealLine l1, RealLine l2);
	std::ostream& operator << (std::ostream& os, const RealVariable& real);
};