#include "solver.hpp"

namespace solver {
    double solve(RealExpression expression) {
        return expression.x->real;
    }

    std::complex<double> solve(ComplexExpression expression) {
        return expression.x->comp;
    }
};