#include <stdio.h>
#include <math.h>
void calc(int x);
int fac(int V);

int main() {
    int x;
    scanf("%d", &x);
    calc(x);
    return 0;
}

void calc(int x) {
    int n;
    float sum = 0;
    for (n=0; n < 11; n++) {
        sum += pow(x, n) / fac(n);
    }
    printf("Result -> %.9f\na", sum);
}

int fac(int V) {
    if (V < 1) {
        return 1;
    }
    return  V * fac(V - 1);

}