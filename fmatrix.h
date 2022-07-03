//
// Created by Ryan Lee on 2022-06-21.
//

#ifndef MATRIX_FMATRIX_H
#define MATRIX_FMATRIX_H

#include <vector>
#include <limits.h>
#include <string>
#include "fraction.h"

using std::vector;

class fMatrix {
private:
    int n, m;
    vector<vector<fraction>> val;

public:
    fMatrix(int _n, int _m, fraction _default) {
        val.resize(_n, vector<fraction>(_m, _default));
        n = _n;
        m = _m;
    }

    int N() { return n; }

    int M() { return m; }

    void setSize(int _n, int _m) {
        n = _n;
        m = _m;
    }

    vector<fraction> &operator[](int x) { return val[x]; }

    vector<fraction> &back() { return val.back(); }

    void push_back() { val.push_back(vector<fraction>(0)); }

    fMatrix cof(int x, int y) {
        fMatrix res(0, 0, fraction(0, 1));
        res.setSize(n - 1, m - 1);

        for (int i = 0; i < n; i++) {
            if (i == x) continue;
            res.push_back();
            for (int j = 0; j < m; j++) {
                if (j == y) continue;
                res.back().push_back(val[i][j]);
            }
        }

        return res;
    }

    fraction det() {
        if (n != m) return {1, 1};
        if (n == 1) return val[0][0];

        fraction res = {0, 1};

        for (int i = 0; i < n; i++) {
            if (i & 1) res = res - val[i][0] * cof(i, 0).det();
            else res = res + val[i][0] * cof(i, 0).det();
        }

        return res;
    }

    std::string to_string() {
        std::string res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j) res += ", ";
                if (val[i][j].getNum() == INT_MAX && val[i][j].getDen() == 1)
                    res += "INF";
                else res += val[i][j].to_string();
            }
            res += '\n';
        }
        res += std::string("----------------------------------------------\n");
        return res;
    }
};

#endif //MATRIX_FMATRIX_H
