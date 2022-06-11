#ifndef META_CPOLYNOMIAL_H
#define META_CPOLYNOMIAL_H

#include <iostream>
#include <cmath>
#include <utility>
#include <array>
#include <algorithm>
#include <string>

template<size_t size = 1>
class CPolynomial {
private:
    const std::array<int, size> coefficients_;
public:

    constexpr explicit CPolynomial(std::array<int, size> coefficients) :
            coefficients_(
                    std::move(
                            coefficients)) {}

    CPolynomial(const CPolynomial &other) : coefficients_(other.coefficients_.size(), 0) {
        for (int i = coefficients_.size() - 1; i >= 0; i--) {
            coefficients_[i] = other.coefficients_[i];
        }
    }

    friend std::ostream &operator<<(std::ostream &out, const CPolynomial &polynomial) {
        int degree = polynomial.coefficients_.size();
        degree--;

        for (int i = degree; i >= 0; i--) {
            if (polynomial.coefficients_[i] == 0) {
                continue;
            } else if (i == 0) {
                if (polynomial.coefficients_[i] > 0) {
                    out << " " << "+" << " " << polynomial.coefficients_[i];
                } else if (polynomial.coefficients_[i] < 0)
                    out << " " << "-" << " " << std::abs(polynomial.coefficients_[i]);
            } else if (i == 1) {
                if (polynomial.coefficients_[1] > 0) {
                    out << " " << "+" << " " << polynomial.coefficients_[i] << "x";
                } else if (polynomial.coefficients_[1] < 0) {
                    out << " " << "-" << " " << std::abs(polynomial.coefficients_[i]) << "x";
                }

            } else if (polynomial.coefficients_[i] == 1 || polynomial.coefficients_[i] == -1) {
                if (i == degree) {
                    if (polynomial.coefficients_[i] == 1) {
                        out << "x^" << i;
                    } else if (polynomial.coefficients_[i] == -1) {
                        out << "-" << "x^" << i;
                    }
                } else if (polynomial.coefficients_[i] > 0) {
                    out << " " << "+" << " " << "x^" << i;
                } else if (polynomial.coefficients_[i] < 0) {
                    out << " " << "-" << " " << "x^" << std::abs(i);
                }
            } else {
                if (i == degree) {
                    out << polynomial.coefficients_[i] << "x^" << i;
                } else if (polynomial.coefficients_[i] > 0) {
                    out << " " << "+" << " " << polynomial.coefficients_[i] << "x^" << i;
                } else if (polynomial.coefficients_[i] < 0) {
                    out << " " << "-" << " " << std::abs(polynomial.coefficients_[i]) << "x^" << i;
                }
            }
        }
        return out;
    }

    friend std::istream &operator>>(std::istream &in, CPolynomial &polynomial) {
        int degree;
        std::cin >> degree;

        polynomial.coefficients_ = std::array<int, size>(degree + 1, 0);

        for (int i = degree; i >= 0; i--) {
            std::cin >> polynomial.coefficients_[i];
        }
        return in;
    }

    constexpr int calculation(int k) {
        int answer = 0;
        if (coefficients_.size() > 1) {
            for (int i = coefficients_.size() - 1; i > 0; i--) {
                answer += coefficients_[i] * pow(k, i);
            }
            answer += coefficients_[0];
            return answer;
        } else {
            return coefficients_[0];
        }
    }


    ~CPolynomial() = default;
};


#endif
