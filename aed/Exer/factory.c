#include <stdio.h>

int fac(int x);

int main() {
    printf("%d", fac(0));
    return 0;
}

int fac(int x) {
    if (x < 1) { return 1; }
    return  x * fac(x - 1);
}