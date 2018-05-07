#include <stdio.h>

void func(int n, char * n1);

int main() {
    int n = 4;
    char n1[]="123040943234432";
    func(n, n1);
    return 0;
}

void func(int n, char * n1) {
    static int count = 0;
    static int i = 0;
    if(i == 15) {
        printf("Quantidade de %d em %s é %d\n", n, n1, count);
        return;
    }
    if((n1[i]-48) == n)
        count++;
    i++;
    return func(n, n1);
}