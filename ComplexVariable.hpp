#pragma once

namespace solver {
    class ComplexVariable {
	private:
        double re;
        double im;
    public:
    	friend ComplexVariable& operator + (ComplexVariable& comp1, ComplexVariable& comp2);
	    friend ComplexVariable& operator + (ComplexVariable& comp, double n);
        friend ComplexVariable& operator + (double n, ComplexVariable& comp);
        friend ComplexVariable& operator + (ComplexVariable& comp1, std::complex<double> comp2);
        friend ComplexVariable& operator + (std::complex<double> comp2, ComplexVariable& comp1);

        friend ComplexVariable& operator - (ComplexVariable& comp1, ComplexVariable& comp2);
	    friend ComplexVariable& operator - (ComplexVariable& comp, double n);
        friend ComplexVariable& operator - (double n, ComplexVariable& comp);
        friend ComplexVariable& operator - (ComplexVariable& comp1, std::complex<double> comp2);
        friend ComplexVariable& operator - (std::complex<double> comp2, ComplexVariable& comp1);

		friend ComplexVariable& operator * (ComplexVariable& comp1, ComplexVariable& comp2);
	    friend ComplexVariable& operator * (ComplexVariable& comp, double n);
        friend ComplexVariable& operator * (double n, ComplexVariable& comp);
        friend ComplexVariable& operator * (ComplexVariable& comp1, std::complex<double> comp2);
        friend ComplexVariable& operator * (std::complex<double> comp2, ComplexVariable& comp1);
        
        friend ComplexVariable& operator / (ComplexVariable& comp1, ComplexVariable& comp2);
        friend ComplexVariable& operator / (ComplexVariable& comp, double n);
        friend ComplexVariable& operator / (double n, ComplexVariable& comp);
        friend ComplexVariable& operator / (ComplexVariable& comp1, std::complex<double> comp2);
        friend ComplexVariable& operator / (std::complex<double> comp2, ComplexVariable& comp1);
        
        friend ComplexVariable& operator ^ (ComplexVariable& comp, double n);

		friend ComplexVariable& operator == (ComplexVariable& comp1, ComplexVariable& comp2);
        friend ComplexVariable& operator == (ComplexVariable& comp, double n);
        friend ComplexVariable& operator == (ComplexVariable& comp1, std::complex<double> comp2);
    };
};