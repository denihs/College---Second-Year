#include <stdio.h>

void func(int n);
int checkEntrada(int n);

int main() {
    int n = 12;
    if(checkEntrada(n))
        func(n);
    return 0;
}

void func(int n) {
    if(n < 0) {
        return;
    }
    if(n%2==0)
        printf("%d, ", n);
    return func(n-1);
}

int checkEntrada(int n) {
    if(n%2==0){
        return 1;
    }
    printf("\n\nNumero não é par\n\n");
    return 0;
}