#include <stdio.h>


int AND(int x1, int x2){
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


int main() {
    int xs[4][2];
    int i, y;

    xs[0][0] = 0; xs[0][1] = 0;
    xs[1][0] = 1; xs[1][1] = 0;
    xs[2][0] = 0; xs[2][1] = 1;
    xs[3][0] = 1; xs[3][1] = 1;

    for (i=0;i<4;i++) {
        y = AND(xs[i][0], xs[i][1]);
        printf("AND(%d, %d) -> %d\n", xs[i][0], xs[i][1], y);
    }

    return 0;
}