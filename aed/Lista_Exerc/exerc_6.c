#include <stdio.h>

#define TAM 5

float * func(float * v, int tam);

int main() {
    float v[]={1,2,3,4,5};
    float * vInvert = func(v, TAM-1);
    for(int i=0; i<TAM; i++) {
        printf("%f ", vInvert[i]);
    }
    return 0;
}

float * func(float * v, int tam) {
    static float vet[TAM];
    static int count = 0;
    if(tam < 0) {
        return vet;
    }
    vet[count] = v[tam];
    tam--;
    count++;
    return func(v, tam);
}