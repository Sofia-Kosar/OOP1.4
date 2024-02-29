#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "Polynomial.h"

Polynomial::Polynomial() : degree(0), coefficients(nullptr) {}

Polynomial::~Polynomial() {
    if (coefficients != nullptr) {
        delete[] coefficients;
    }
}

void Polynomial::Init(int degree, const double* coefficients) {
    this->degree = degree;
    this->coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; ++i) {
        this->coefficients[i] = coefficients[i];
    }
}
void Polynomial::Read() {
    std::cout << "Enter the degree of the polynomial: ";
    std::cin >> degree;
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; ++i) {
        std::cout << "Enter coefficient a" << i << ": ";
        std::cin >> coefficients[i];
    }
}

void Polynomial::Display() const {
    std::cout << toString() << std::endl;
}
std::string Polynomial::toString() const {
    std::ostringstream oss;
    oss << "P(x) = ";
    for (int i = 0; i <= degree; ++i) {
        if (i != 0) oss << " + ";
        oss << coefficients[i] << "·x^" << i;
    }
    return oss.str();
}

int Polynomial::getDegree() const {
    return degree;
}

void Polynomial::setDegree(int degree) {
    this->degree = degree;
}
double* Polynomial::getCoefficients() const {
    return coefficients;
}

void Polynomial::setCoefficients(const double* coefficients) {
    delete[] this->coefficients;
    this->coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; ++i) {
        this->coefficients[i] = coefficients[i];
    }
}

double Polynomial::evaluate(double x) const {
    double result = 0;
    for (int i = 0; i <= degree; ++i) {
        result += coefficients[i] * std::pow(x, i);
    }
    return result;
}

Polynomial Polynomial::add(const Polynomial& other) const {
    int maxDegree = std::max(degree, other.degree);
    double* resultCoefficients = new double[maxDegree + 1];
    for (int i = 0; i <= maxDegree; ++i) {
        resultCoefficients[i] = 0;
        if (i <= degree) resultCoefficients[i] += coefficients[i];
        if (i <= other.degree) resultCoefficients[i] += other.coefficients[i];
    }
    Polynomial result;
    result.Init(maxDegree, resultCoefficients);
    delete[] resultCoefficients;
    return result;
}
Polynomial Polynomial::subtract(const Polynomial& other) const {
    int maxDegree = std::max(degree, other.degree);
    double* resultCoefficients = new double[maxDegree + 1];
    for (int i = 0; i <= maxDegree; ++i) {
        resultCoefficients[i] = 0;
        if (i <= degree) resultCoefficients[i] += coefficients[i];
        if (i <= other.degree) resultCoefficients[i] -= other.coefficients[i];
    }
    Polynomial result;
    result.Init(maxDegree, resultCoefficients);
    delete[] resultCoefficients;
    return result;
}
Polynomial Polynomial::multiply(const Polynomial& other) const {
    int resultDegree = degree + other.degree;
    double* resultCoefficients = new double[resultDegree + 1];
    for (int i = 0; i <= resultDegree; ++i) {
        resultCoefficients[i] = 0;
    }
    for (int i = 0; i <= degree; ++i) {
        for (int j = 0; j <= other.degree; ++j) {
            resultCoefficients[i + j] += coefficients[i] * other.coefficients[j];
        }
    }
    Polynomial result;
    result.Init(resultDegree, resultCoefficients);
    delete[] resultCoefficients;
    return result;
}