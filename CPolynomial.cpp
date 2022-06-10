#include "CPolynomial.h"

CPolynomial::CPolynomial(std::vector<int> coefficients) :
        coefficients_(
                std::move(
                        coefficients)) {}

CPolynomial::CPolynomial(const CPolynomial &other) : coefficients_(other.coefficients_.size(), 0) {
    for (int i = coefficients_.size() - 1; i >= 0; i--) {
        coefficients_[i] = other.coefficients_[i];
    }
}

std::ostream &operator<<(std::ostream &out, const CPolynomial &polynomial) {
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

std::istream &operator>>(std::istream &in, CPolynomial &polynomial) {
    int degree;
    std::cin >> degree;

    polynomial.coefficients_ = std::vector<int>(degree + 1, 0);

    for (int i = degree; i >= 0; i--) {
        std::cin >> polynomial.coefficients_[i];
    }
    return in;
}

constexpr int CPolynomial::calculation(int k) const {
    int answer = 0;
    if (coefficients_.size() > 1) {
        for (int i = coefficients_.size() - 1; i > 0; i--) {
            answer += pow(coefficients_[i] * k, i);
        }
        answer += coefficients_[0];
        return answer;
    } else {
        return coefficients_[0];
    }
}


CPolynomial::~CPolynomial() = default;