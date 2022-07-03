#include <iostream>
#include "fraction.h"
#include "fmatrix.h"

void solve() {
    int vertexNum, edgeNum;

    std::cin >> vertexNum >> edgeNum;
    fMatrix Res = fMatrix(vertexNum, vertexNum, fraction(INT_MAX, 1));
    fMatrix Kir = fMatrix(vertexNum - 1, vertexNum - 1, fraction(0, 1));

    for (int i = 0; i < edgeNum; i++) {
        int a, b;
        fraction R;

        std::cin >> a >> b;
        --a;
        --b;
        R.input();

        Res[a][b] = Res[b][a] = R;
    }

//    std::cout << Res.to_string();

    for (int i = 0; i < vertexNum; i++)
        for (int j = 0; j < vertexNum; j++)
            Res[i][j].inverse();

//    std::cout << Res.to_string();

    for (int i = 0; i < vertexNum - 1; i++) {
        for (int j = 0; j < vertexNum - 1; j++) {
            if (i == j) {
                for (int k = 0; k < vertexNum; k++) {
                    Kir[i][j] = Kir[i][j] + Res[i][k];
                }
            }
            else Kir[i][j] = Res[i][j] * fraction(-1, 1);
        }
    }

//    std::cout << Kir.to_string();

    std::cout << "Resistance is : " << Kir.cof(0, 0).det().getVal() / Kir.det().getVal();
}

int main() {
    std::freopen("./input/1.txt", "r", stdin);
//    std::freopen("./input/2.txt", "r", stdin);
    solve();

    return 0;
}
