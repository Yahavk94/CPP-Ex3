#pragma once

#include <iostream>
#include <complex>
#include "RealVariable.hpp"
#include "ComplexVariable.hpp"

using namespace std;

namespace solver {
    double solve(RealVariable real);
    complex<double> solve(ComplexVariable complex);
};