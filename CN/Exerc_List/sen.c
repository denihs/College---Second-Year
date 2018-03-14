#include <stdio.h>
#include <math.h>

int fac(int V);
double sen(double x);

int main() {
    double x = 0;
    printf("%.9f", sen(x));
    return 0;
}

double sen(double x) {
    int i, n = 1;
    double senValue = 0;

    for (i=0; i< 8; i++) {
        if (i % 2 == 0) {
            senValue += pow(x, n) / fac(n);
        } else {
            senValue -= pow(x, n) / fac(n);
        }
        n += 2;
        return senValue;
    }
}

int fac(int V) {
    if (V < 1) {
        return 1;
    }
    return  V * fac(V - 1);

}