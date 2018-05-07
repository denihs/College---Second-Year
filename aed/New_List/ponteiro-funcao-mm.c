#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mm(const int * vet, int * min, int * max) {
    *min = vet[0];
    *max = vet[0];
    for(int i=1; i < 10; i++) {
        if(vet[i] < *min)
             *min = vet[i];
        if(vet[i] > *max)
             *max = vet[i];
    }
}

void show(const int * vet) {
    printf("vet -> ");
    for(int i=0; i < 10; i++) {
        printf("%d ", vet[i]);
    }
}

void fill(int *  vet) {
    for(int i=0; i < 10; i++) {
        vet[i] = rand()%10 + 1;
    }
    show(vet);
}

int main() {
    srand((unsigned)time(NULL));
    int *vet = (int*) malloc(sizeof(int) * 10), min, max;
    fill(vet);
    mm(vet, &min, &max);
    printf("\n\nmin = %d, max = %d\n\n", min, max);
    free(vet);
    return 0;
}