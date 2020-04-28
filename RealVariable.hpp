#pragma once

namespace solver {
    class RealVariable {
	private:
        double re;
    public:
		friend RealVariable& operator + (RealVariable& re1, RealVariable& re2);
	    friend RealVariable& operator + (RealVariable& re, double n);
        friend RealVariable& operator + (double n, RealVariable& re);

		friend RealVariable& operator - (RealVariable& re1, RealVariable& re2);
		friend RealVariable& operator - (RealVariable& re, double n);
		friend RealVariable& operator - (double n, RealVariable& re);

		friend RealVariable& operator * (RealVariable& r1, RealVariable& r2);
		friend RealVariable& operator * (RealVariable& re, double n);
        friend RealVariable& operator * (double n, RealVariable& re);

		friend RealVariable& operator / (RealVariable& re1, RealVariable& re2);
		friend RealVariable& operator / (RealVariable& re, double n);
        friend RealVariable& operator / (double n, RealVariable& re);

        friend RealVariable& operator ^ (RealVariable& re, double n);

		friend RealVariable& operator == (RealVariable& re1, RealVariable& re2);
        friend RealVariable& operator == (RealVariable& re, double n);
    };
};