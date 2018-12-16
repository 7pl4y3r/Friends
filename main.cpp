#include <iostream>

int a[20][20], n = 7, k, viz[20], c[20], prim, ultim, prieteni[20], contor, k1;
int ince[20];
bool n_am = false;

void init() {

    a[1][2] = a[2][1] = 1;
    a[1][6] = a[6][1] = 1;
    a[1][7] = a[7][1] = 1;
    a[2][6] = a[6][2] = 1;
    a[2][7] = a[7][2] = 1;
    a[3][4] = a[4][3] = 1;
    a[4][5] = a[5][4] = 1;

    prim = ultim = 1;
    c[ultim] = k;
    viz[k] = 1;
}

void prelu() {

    k = c[prim];
    contor = 0;
    for(int i = 1; i <= n; i++)
    if(a[k][i] == 1 && viz[i] == 0) {

        ultim++;
        c[ultim] = i;
        viz[i] = 1;
        contor++;

    }

    k1++;
    prieteni[k1] = contor;
    ince[k1] = k;

    prim++;
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
    while(prim <= ultim)
    prelu();

    int maxi = 0, start;
    for(int i = 1; i <= k1; i++)
    if(prieteni[i] > maxi) {
    maxi = prieteni[i];
    start = ince[i];

    }

    init();
    while(prim <= ultim && !n_am) {

        prelu();
        if(k == start)
        n_am = true;

    }

    prelu();
    for(int i = 1; i <= n; i++)
    std::cout << c[i] << ' ';

    return 0;
}