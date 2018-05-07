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
    static int i=0;
    if(i >= n) {
        printf("%d ", n);
        return;
    }
    if(i%2==0)
        printf("%d, ", i);
    i++;
    return func(n);
}

int checkEntrada(int n) {
    if(n%2==0){
        return 1;
    }
    printf("\n\nNumero não é par\n\n");
    return 0;
}