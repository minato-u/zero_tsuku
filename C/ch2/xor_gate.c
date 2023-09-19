#include <stdio.h>


int AND(int x1, int x2) {
    double x[2], w[2], b, tmp;

    x[0] = (double)x1; x[1] = (double)x2;
    w[0] = 0.5; w[1] = 0.5;
    b = -0.7;
    tmp = x[0]*w[0] + x[1]*w[1] + b;

    if (tmp <= 0.) {
        return 0;
    } else {
        return 1;
    }
}

int NAND(int x1, int x2) {
    double x[2], w[2], b, tmp;

    x[0] = (double)x1; x[1] = (double)x2;
    w[0] = -0.5; w[1] = -0.5;
    b = 0.7;
    tmp = x[0]*w[0] + x[1]*w[1] + b;

    if (tmp <= 0.) {
        return 0;
    } else {
        return 1;
    }
}

int OR(int x1, int x2) {
    double x[2], w[2], b, tmp;

    x[0] = (double)x1; x[1] = (double)x2;
    w[0] = 0.5; w[1] = 0.5;
    b = -0.2;
    tmp = x[0]*w[0] + x[1]*w[1] + b;

    if (tmp <= 0.) {
        return 0;
    } else {
        return 1;
    }
}

int XOR(int x1, int x2) {
    int s1, s2, y;

    s1 = NAND(x1, x2);
    s2 = OR(x1, x2);
    y = AND(s1, s2);

    return y;
}


int main() {
    int xs[4][2];
    int i, y;

    xs[0][0] = 0; xs[0][1] = 0;
    xs[1][0] = 1; xs[1][1] = 0;
    xs[2][0] = 0; xs[2][1] = 1;
    xs[3][0] = 1; xs[3][1] = 1;

    for (i=0;i<4;i++) {
        y = XOR(xs[i][0], xs[i][1]);
        printf("XOR(%d, %d) -> %d\n", xs[i][0], xs[i][1], y);
    }

    return 0;
}