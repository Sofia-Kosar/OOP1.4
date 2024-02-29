#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

class Polynomial {
private:
    int degree;
    double* coefficients;

public:
    Polynomial();
    ~Polynomial();
    void Init(int degree, const double* coefficients);
    void Read();
    void Display() const;
    std::string toString() const;

    int getDegree() const;
    void setDegree(int degree);
    double* getCoefficients() const;
    void setCoefficients(const double* coefficients);
    double evaluate(double x) const;
    Polynomial add(const Polynomial& other) const;
    Polynomial subtract(const Polynomial& other) const;
    Polynomial multiply(const Polynomial& other) const;
};
