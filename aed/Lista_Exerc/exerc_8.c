#include <stdio.h>

void func(int n);

int main() {
    func(10);
    return 0;
}

void func(int n) {
    if(n < 0) {
        return;
    }
    printf("%d, ", n);
    return func(n-1);
}