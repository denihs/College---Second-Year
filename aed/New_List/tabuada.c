#include <stdio.h>

int validate();
void tab(int n);

int main () {
    int n = validate();
    if (n) {
        tab(n);
    }

    return 0;
}

int validate() {
    int n;
    printf("Number -> ");
    scanf("%d", &n);
    if (n > 0)
        return n;
    printf("Error!");
    return 0;
}

void tab(int n) {
    for (int i=0; i < 11; i++) {
        printf("%.2d X %d = %.d\n", i, n, n*i);
    }
}