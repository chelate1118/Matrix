//
// Created by Ryan Lee on 2022-06-21.
//

#ifndef MATRIX_FRACTION_H
#define MATRIX_FRACTION_H

#include <string>

int abs(int x) {
    return x < 0 ? -x : x;
}

int gcd(int n, int m) {
    if (m == 0) return n;
    return abs(gcd(m, n % m));
}

int lcm(int n, int m) {
    return n * m / gcd(n, m);
}

class fraction {
private:
    int num, den;

    fraction refactor() {
        if (den < 0) den *= -1, num *= -1;
        return *this;
    }

public:
    fraction(int _num, int _den) {
        num = _num / gcd(_num, _den);
        den = _den / gcd(_num, _den);
    }

    fraction() { num = den = 1; }

    /// Getter
    double getVal() { return (double) num / den; }

    int getNum() { return num; }

    int getDen() { return den; }

    /// Setter
    void setNum(int _num) {
        num = _num;

        int GCD = gcd(num, den);
        num /= GCD;
        den /= GCD;
    }

    void setDen(int _den) {
        den = _den;

        int GCD = gcd(num, den);
        num /= GCD;
        den /= GCD;
    }

    /// Operator
    fraction operator*(fraction x) {
        return fraction(num * x.num, den * x.den).refactor();
    }

    fraction operator+(fraction x) {
        int _den = lcm(den, x.den);
        int _num = num * _den / den + x.num * _den / x.den;

        return fraction(_num, _den).refactor();
    }

    fraction operator-(fraction x) {
        return (*this + x * fraction(-1, 1)).refactor();
    }

    std::string to_string() {
        return std::to_string(num) + " / " + std::to_string(den);
    }

    fraction input() {
        int _num, _den;
        char c;
        std::cin >> _num >> c >> _den;

        if (c != '/') std::cout << "Error!";

        num = _num;
        den = _den;

        return *this;
    }
};

#endif //MATRIX_FRACTION_H
