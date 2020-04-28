#include "MyUtils.hpp"
#include "solver.hpp"
#include "doctest.h"

#include <iostream>
#include <string>

using namespace solver;

TEST_CASE("Test for real equations") { // 14
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

TEST_CASE("Test for complex equations") { // 15
    ComplexVariable x;
    CHECK(solve(x*2 == 4) == std::complex<double>(0,0));
    CHECK(solve(x+2 == 4) == std::complex<double>(0,0));
    CHECK(solve(x*2 + x*5 == 7) == std::complex<double>(0,0));
    CHECK(solve(x-2 == 2) == std::complex<double>(0,0));
    CHECK(solve(x+2-(2-x) == 2) == std::complex<double>(0,0));
    CHECK(solve(2*(x-2) == 2) == std::complex<double>(0,0));
    CHECK(solve(x*2 + x*5 - x*6 == 7) == std::complex<double>(0,0));
    CHECK(solve(x/2 == 2) == std::complex<double>(0,0));
    CHECK(solve(x + x/2 == 6) == std::complex<double>(0,0));
    CHECK(solve(2*x - x/2 == 6) == std::complex<double>(0,0));
    CHECK(solve((x^2) == 4) == std::complex<double>(0,0));
    CHECK(solve((x^2) + 2*x - 2 == -4) == std::complex<double>(0,0));
    CHECK(solve((((2*x)^2) + 8*x + 16)/4 == -1) == std::complex<double>(0,0));
    CHECK(solve((x^2) == -4) == std::complex<double>(0,0));
    CHECK(solve((x^2)/2 == -8) == std::complex<double>(0,0));
}

TEST_CASE("Test for chaining in real equations") { // 14
    RealVariable x;
    CHECK(solve((x*2)*2 == 4) == 1);
    CHECK(solve(x+2+2+2+2+2 == 10) == 1);
    CHECK(solve((x*2)*2 + (x*5)*5 == 29) == 1);
    CHECK(solve(x-2-2-2-2-2-2 == -2) == 1);
    CHECK(solve(x+2-(2-x)+(x+7)-(3-x)-x == 2) == 1);
    CHECK(solve(2*(2*(x-2)) == 2) == 1);
    CHECK(solve((x*2)*2 + (x*5)*5 - (x*6)*6 == 17) == 1);
    CHECK(solve(((x/2)/2)/2 == 2) == 1);
    CHECK(solve(x + x/2 + x/4 + x/8 == 61) == 1);
    CHECK(solve(4*(2*x) - (x/2)/2 == 6*12) == 1);
    CHECK(solve(((x^2)*2)*7 == 4) == 1);
    CHECK(solve((x^2) + 2*x - 2 == -3) == 1);
    CHECK(solve((((2*x)^2) + (9*(8*x)^2) + 16)/4 == 7) == 1);
    CHECK(solve((((2*x)/21)^2) == 8) == 1);
}

TEST_CASE("Test for chaining in complex equations") { // 16
    ComplexVariable x;
    CHECK(solve((x*2)*2 == 4) == std::complex<double>(0,0));
    CHECK(solve(x+2+2+2+2+2 == 10) == std::complex<double>(0,0));
    CHECK(solve((x*2)*2 + (x*5)*5 == 29) == std::complex<double>(0,0));
    CHECK(solve(x-2-2-2-2-2-2 == -2) == std::complex<double>(0,0));
    CHECK(solve(x+2-(2-x)+(x+7)-(3-x)-x == 2) == std::complex<double>(0,0));
    CHECK(solve(2*(2*(x-2)) == 2) == std::complex<double>(0,0));
    CHECK(solve((x*2)*2 + (x*5)*5 - (x*6)*6 == 17) == std::complex<double>(0,0));
    CHECK(solve(((x/2)/2)/2 == 2) == std::complex<double>(0,0));
    CHECK(solve(x + x/2 + x/4 + x/8 == 61) == std::complex<double>(0,0));
    CHECK(solve(4*(2*x) - (x/2)/2 == 6*12) == std::complex<double>(0,0));
    CHECK(solve(((x^2)*2)*7 == 4) == std::complex<double>(0,0));
    CHECK(solve((x^2) + 2*x - 2 == -3) == std::complex<double>(0,0));
    CHECK(solve((((2*x)^2) + (9*(8*x)^2) + 16)/4 == 7) == std::complex<double>(0,0));
    CHECK(solve((((2*x)/21)^2) == 8) == std::complex<double>(0,0));
    CHECK(solve((((2*x)^2)/7) == -4) == std::complex<double>(0,0));
    CHECK(solve((((2*x)^2)/2)/4 == -8) == std::complex<double>(0,0));
}

TEST_CASE("Test for real exceptions") {
    RealVariable x;
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
    CHECK(solve(x+2 == 4) == 1);
    CHECK(solve(x*2 + x*5 == 7) == 1);
    CHECK(solve(x-2 == 2) == 1);
}