#ifndef META_CPOLYNOMIAL_H
#define META_CPOLYNOMIAL_H

#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>

class CPolynomial {
private:
    std::vector<int> coefficients_;
public:

    explicit CPolynomial(std::vector<int> coefficients = std::vector<int>());

    CPolynomial(const CPolynomial &other);

    friend std::ostream &operator<<(std::ostream &out, const CPolynomial &polynomial);

    friend std::istream &operator>>(std::istream &in, CPolynomial &polynomial);

    [[nodiscard]] constexpr int calculation(int k) const;


    ~CPolynomial();
};


#endif
