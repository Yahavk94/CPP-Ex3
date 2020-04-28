#include "solver.hpp"

using solver::RealVariable;
using solver::ComplexVariable;

complex<double> solver::solve(ComplexVariable c) {
    return std::complex<double>(0,0);
}

double solver::solve(RealVariable r) {
    return 1;
}