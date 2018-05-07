#include <stdio.h>

#define VALUE 10
#define LENGTH 11

void showVet(int * vet);
int menu (int * vet);
int subMenu();
void maiorElementoIterativo(const int * v);
int maiorElementoRecursivo(int * v, int n);
void menorElementoIterativo(const int * v);
int menorElementoRecursivo(int * v, int n);
int somatorioIterativo(const int * v);
int somatorioRecursivo(int * v, int n);
void produtoIterativo(const int * v);
int produtoRecursivo(int * v, int n);
void mediaIterativa(int * v);
void mediaRecursiva(int * v, int n);

int main () {
    int vet[]={4,2,1,5,6,1,7,8,9,3, VALUE};
    int looping;
    do {
        looping=menu(vet);
    }while(looping);
    return 0;
}

void showVet(int * vet) {
    printf("\nVet -> ");
    for (int i=0; i < LENGTH; i++) {
        printf("%d ", vet[i]);
    }
}

int subMenu() {
    int op;
    printf("\n[1] Iterarivo\n");
    printf("[2] Recursivo\n");
    printf("-> ");
    scanf("%d",&op);

    switch (op) {
        case 1:
            break;
        case 2:
            break;
        default:
            printf("\n\nOp invalida\n\n");
            return 0;
    }
    return op;
}

int menu (int * vet) {
    int op1, op2;
    showVet(vet);
    printf("\n[1] O elemento maximo do vetor\n");
    printf("[2] O elemento minimo do vetor\n");
    printf("[3] A soma dos elementos do vetor\n");
    printf("[4] O produto dos elementos do vetor\n");
    printf("[5] A média dos elementos do vetor\n");
    printf("[0] Dar o fora dai\n");
    printf("---> ");
    scanf("%d", &op1);

    switch ( op1 ) {
        case 1:
            op2 = subMenu();
            if (op2) {
                op2 == 1 ? maiorElementoIterativo(vet) : maiorElementoRecursivo(vet, LENGTH-1);
            }
            break;
        case 2:
            op2 = subMenu();
            if (op2) {
                op2 == 1 ? menorElementoIterativo(vet) : menorElementoRecursivo(vet, LENGTH-1);
            }
            break;
        case 3:
            op2 = subMenu();
            if (op2) {
                op2 == 1 ? somatorioIterativo(vet) : somatorioRecursivo(vet, LENGTH-1);
            }
            break;
        case 4:
            op2 = subMenu();
            if (op2) {
                op2 == 1 ? produtoIterativo(vet) : produtoRecursivo(vet, LENGTH-1);
            }
            break;
        case 5:
            op2 = subMenu();
            if (op2) {
                op2 == 1 ? mediaIterativa(vet) : mediaRecursiva(vet, LENGTH-1);
            }
            break;
        case 0:
            return 0;
        default:
            printf("\nPutz.... \n");

    }
    return 1;
}
void maiorElementoIterativo(const int * v) {
    int M = v[0];
    for(int i=1; i < LENGTH; i ++) {
        v[i] > M ? M = v[i] : M;
    }
    printf("\nO maior numero no vetor é %d\n", M);
}
int maiorElementoRecursivo(int * v, int n) {
    static int M = 0;
    if (n < 0) {
        printf("\nO maior numero no vetor é %d\n", M);
        return 0;
    }
    v[n] > M ? M = v[n] : M;
    n--;
    return maiorElementoRecursivo(v,n);
}
void menorElementoIterativo(const int * v) {
    int M = v[0];
    for(int i=1; i < LENGTH; i ++) {
        v[i] < M ? M = v[i] : M;
    }
    printf("\nO menor numero no vetor é %d\n", M);
}
int menorElementoRecursivo(int * v, int n) {
    static int M = LENGTH;
    if (n < 0) {
        printf("\nO menor numero no vetor é %d\n", M);
        return 0;
    }
    v[n] < M ? M = v[n] : M;
    n--;
    return menorElementoRecursivo(v,n);
}

int somatorioIterativo(const int * v) {
    int sum = 0;
    for (int i=0; i < LENGTH; i++) {
        sum += v[i];
    }
    printf("\nSoma de todos os numero é %d\n", sum);
    return sum;
}

int somatorioRecursivo(int * v, int n) {
    static int sum = 0;
    if (n < 0) {
        printf("\nSoma de todos os numero é %d\n", sum);
        return sum;
    }
    sum += v[n];
    n--;
    return somatorioRecursivo(v, n);
}

void produtoIterativo(const int * v) {
    int sum = 1;
    for (int i=0; i < LENGTH; i++) {
        sum *= v[i];
    }
    printf("\nO produto de todos os numero é %d\n", sum);
}

int produtoRecursivo(int * v, int n) {
    static int sum = 1;
    if (n < 0) {
        printf("\nO produto de todos os numero é %d\n", sum);
        return sum;
    }
    sum *= v[n];
    n--;
    return produtoRecursivo(v, n);
}
void mediaIterativa(int * v ) {
    float soma = somatorioIterativo(v);
    printf("A media é %.2f", soma / LENGTH);
}

void mediaRecursiva(int * v, int n) {
    float soma = somatorioRecursivo(v, n);
    printf("A media é %.2f", soma / LENGTH);
}