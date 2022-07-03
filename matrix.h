//
// Created by Ryan Lee on 2022-06-21.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <vector>
#include <limits.h>
#include <string>
#include "fraction.h"

using std::vector;

class matrix {
private:
    int n, m;
    vector<vector<fraction>> val;

public:
    matrix(int _n, int _m) {
        val.resize(_n, vector<fraction>(_m));
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

    matrix cof(int x, int y) {
        matrix res(0, 0);
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
                res += val[i][j].to_string();
            }
            res += '\n';
        }
        return res;
    }
};

#endif //MATRIX_MATRIX_H
