#include <stdio.h>
int func(int n);

int main() {
    printf("%d",func(6));
    return 0;
}

int func(int n) {
    int sum = 0;
    for (int i=n; i > 0; i--) {
        sum += i;
    }
    return sum;
}