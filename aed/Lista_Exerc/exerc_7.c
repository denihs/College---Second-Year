#include <stdio.h>

void func(int n);

int main() {
    func(10);
    return 0;
}

void func(int n) {
    static int i=1;
    if(i >= n) {
        printf("%d ", n);
        return;
    }
    printf("%d, ", i);
    i++;
    return func(n);
}