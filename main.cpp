#include <iostream>
#include "fraction.h"
#include "matrix.h"

int main() {
    matrix x(3, 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            x[i][j].input();
        }
    }

    std::cout << x.to_string() << '\n';

    std::cout << x.det().to_string();

    return 0;
}
