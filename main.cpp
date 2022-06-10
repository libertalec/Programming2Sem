#include <iostream>
#include "CPolynomial.h"

int main() {
    std::vector<int> polynomial1 = {2, 3, -1};
    CPolynomial constexpr one(polynomial1);
    static_assert(one.calculation(2) == 12, "!!!");

    return 0;
}
