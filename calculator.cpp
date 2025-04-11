#include "calculator.h"
#include <stdexcept>
#include <limits>

int Calculator::add(int a, int b) {
    if ((b > 0) && (a > std::numeric_limits<int>::max() - b))
        throw std::overflow_error("add1");
    if ((b < 0) && (a < std::numeric_limits<int>::min() - b))
        throw std::overflow_error("add2");
    return a + b;
}

int Calculator::sub(int a, int b) {
    if ((b < 0) && (a > std::numeric_limits<int>::max() + b))
        throw std::overflow_error("sub1");
    if ((b > 0) && (a < std::numeric_limits<int>::min() + b))
        throw std::overflow_error("sub2");
    return a - b;
}

int Calculator::mul(int a, int b) {
    if (a > 0) {
        if (b > 0 && a > std::numeric_limits<int>::max() / b)
            throw std::overflow_error("mul1");
        if (b < 0 && b < std::numeric_limits<int>::min() / a)
            throw std::overflow_error("mul2");
    } else if (a < 0) {
        if (b > 0 && a < std::numeric_limits<int>::min() / b)
            throw std::overflow_error("mul1");
        if (b < 0 && a < std::numeric_limits<int>::max() / b)
            throw std::overflow_error("mul2");
    }
    return a * b;
}

int Calculator::div(int a, int b) {
    if (b == 0)
        throw std::invalid_argument("div1");
    if (a == std::numeric_limits<int>::min() && b == -1)
        throw std::overflow_error("div2");
    return a / b;
}
