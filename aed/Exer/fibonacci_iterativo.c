#include <stdio.h>

int calc(int x);

int main() {
    int x = 1000;
    calc(x);
    return  0;
}

int calc(int x) {
    int a = 1, b = 1, c = 0, i;
    printf("\n1 1 ");
    for (i=2; i < x; i++){
        c = a + b;
        b = a;
        a = c;
        printf("%d ", c);
    }
}