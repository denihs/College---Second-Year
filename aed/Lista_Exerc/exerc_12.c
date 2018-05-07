#include <stdio.h>
#include <math.h>

void func(int n);

int main() {
    int n = 170;
    func(n);
    return 0;
}

void func(int n) {
    static int divisor = 0;
    static int foo = 0;
    static int binary = 0;
    if(n <= 0) {
        printf("%d\n",binary);
        return;
    }
    binary += (n%2)*pow(10, foo);
    divisor = n/2;
    foo++;
    return func(divisor);
}