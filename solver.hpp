#include "RealVariable.hpp"
#include "ComplexVariable.hpp"

using solver::RealLine;
using solver::RealVariable;
using solver::ComplexExpression;
using solver::ComplexVariable;

namespace solver {
    RealVariable solve(const std::istream& expression);
    //ComplexVariable solve(ComplexLine line);
};