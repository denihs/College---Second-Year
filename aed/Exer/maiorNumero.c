#include <stdio.h>

float greaterThan(float * V);

int main() {
    float a[]={8, 6, 7};
    printf("%f", greaterThan(a));
    return 0;
}

float greaterThan(float * V) {
    return V[0] > V[1] && V[0] > V[2] ? V[0] : ( V[1] > V[2] ? V[1] : V[2]);
}