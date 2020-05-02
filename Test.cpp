#include "solver.hpp"
#include "doctest.h"

#include <iostream>
#include <string>

using namespace solver;

TEST_CASE("Test for real equations") { // 15
    RealVariable x;
    CHECK(solve(x*2 == 4) == 1);
    CHECK(solve(x+2 == 4) == 1);
    CHECK(solve(x*2 + x*5 == 7) == 1);
    CHECK(solve(x-2 == 2) == 1);
    CHECK(solve(x+2-(2-x) == 2) == 1);
    CHECK(solve(2*(x-2) == 2) == 1);
    CHECK(solve(x*2 + x*5 - x*6 == 7) == 1);
    CHECK(solve(x/2 == 2) == 1);
    CHECK(solve(x + x/2 == 6) == 1);
    CHECK(solve(2*x - x/2 == 6) == 1);
    CHECK(solve((x^2) == 4) == 1);
    CHECK(solve((x^2) + 2*x - 2 == -3) == 1);
    CHECK(solve((((2*x)^2) + 8*x + 16)/4 == 7) == 1);
    CHECK(solve((x^2)/2 == 8) == 1);
}

/*TEST_CASE("Test for complex equations") { // 15
    ComplexVariable x;
    CHECK(solve(x*2 == 4) == std::complex<double>(2,0));
    CHECK(solve(x+2 == 4) == std::complex<double>(2,0));
    CHECK(solve(x*2 + x*5 == 7) == std::complex<double>(1,0));
    CHECK(solve(x-2 == 2) == std::complex<double>(4,0));
    CHECK(solve(x+2-(2-x) == 2) == std::complex<double>(1,0));
    CHECK(solve(2*(x-2) == 2) == std::complex<double>(3,0));
    CHECK(solve(x*2 + x*5 - x*6 == 7) == std::complex<double>(1,0));
    CHECK(solve(x/2 == 2) == std::complex<double>(4,0));
    CHECK(solve(x + x/2 == 6) == std::complex<double>(4,0));
    CHECK(solve(2*x - x/2 == 6) == std::complex<double>(4,0));
    CHECK(solve((x^2) == 4) == std::complex<double>(2,0));
    CHECK(solve((x^2) + 2*x - 2 == -4) == std::complex<double>(-1,1));
    CHECK(solve((((2*x)^2) + 8*x + 16)/4 == -1) == std::complex<double>(-1,2));
    CHECK(solve((x^2) == -4) == std::complex<double>(0,2));
    CHECK(solve((x^2)/2 == -8) == std::complex<double>(0,4));
}*/