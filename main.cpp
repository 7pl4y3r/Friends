#include <iostream>

int a[20][20], n = 7;

void init() {

    a[1][2] = a[2][1] = 1;
    a[1][6] = a[6][1] = 1;
    a[1][7] = a[7][1] = 1;
    a[2][6] = a[6][2] = 1;
    a[2][7] = a[7][2] = 1;
    a[3][4] = a[4][3] = 1;
    a[4][5] = a[5][4] = 1;

    
}

void roy_warshall() {

    for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    if(a[i][j] == 0 && i != k && k != j)
    a[i][j] = a[i][k] * a[k][j];
}

void prntMatrix() {

    for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++)
        std::cout << a[i][j] << ' ';

        std::cout << '\n';
    }

}

int main() {

    init();
    roy_warshall();
    prntMatrix();

    return 0;
}