#include <stdio.h>
#include <math.h>
double distance(float * coordA, float * coordB);

int main() {
    float a[]={0, 3}, b[]={4, 0};
    printf("%f", distance(a, b));
    return 0;
}

double distance(float * coordA, float * coordB) {
    return sqrt( pow((coordB[0] - coordA[0]), 2) + pow(( coordB[1] - coordA[1] ), 2));
}