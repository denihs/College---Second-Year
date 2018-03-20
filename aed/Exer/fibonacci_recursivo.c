#include <stdio.h>

int calc(int x);

int main() {
    int x = 1000;
    printf("\n%d\n", calc(x));
    return  0;
}

int calc(int x) {
    if (x <= 2) {
        return 1;
    }
    return calc(x-1) + calc(x-2);
}