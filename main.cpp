#include <iostream>
#include "fraction.h"
#include "fmatrix.h"

void solve() {
    int vertexNum, edgeNum;

    std::cin >> vertexNum >> edgeNum;
    fMatrix Res = fMatrix(vertexNum, vertexNum);

    for (int i = 0; i < edgeNum; i++) {
        int a, b;
        fraction R;

        std::cin >> a >> b;
        --a; --b;
        R.input();

        Res[a][b] = Res[b][a];
    }

    for (int i = 0; i < vertexNum; i++)
        for (int j = 0; j < vertexNum; j++)
            Res[i][j].inverse();



    std::cout << Res.to_string();
}

int main() {
    std::freopen("./input/1.txt", "r", stdin);
    solve();
    return 0;
}
