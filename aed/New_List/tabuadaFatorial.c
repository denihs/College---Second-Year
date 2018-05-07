#include <stdio.h>

int menu();
int validate();
void tab(int n);
int fac(int x);

int main () {
    int i;
    do{
        i = menu();
    }while (i);
    return 0;
}

int menu() {
    int n, op;
    printf("1 - Tabuada\n2 - Fatorial\n0 - SAIR\n--> ");
    scanf("%d", &n);

    switch (n) {
        case 1:
            op = validate();
            if (op) {
                tab(op);
            }
            break;
        case 2:
            op = validate();
            printf("%d\n", fac(op));
            break;
        case 0:
            return 0;
        default:
            printf("Opção invalida");
    }
    return 1;
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

int fac(int x) {
    if (x <= 1) { printf("%d = ",x); return 1; }
    printf("%d X ", x);
    return  x * fac(x - 1);
}