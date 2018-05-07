#include <stdio.h>
#include <stdlib.h>
#include "DinamicAlocation.h"

int validarEntrada();
void insulator(float ** M, float ** variables, int TAM);
void applyMethod(float ** M, float ** vetSoluction, float error, int TAM);
float bigger(float ** vet, int TAM);
void trocarLinha(float ** M, int TAM);
float calculoDeterminante(float ** M, int nTrocas, int TAM);
float modulo(float n);
int howChange(float ** M, int n, int TAM);

int main(int argc, char *argv[]) {

    float **Matriz, **vetSolution, error, determinante;

    printf("Informe a dimensão da matriz->> ");
    int x = validarEntrada();
    if (x) {

        Matriz = Aloca(x,x+1);
        printf("Valores da Matriz: \n");
        Matriz = preencher(Matriz, x,x);


        vetSolution = Aloca(x, 1);
        printf("Vetor solucao: \n");
        for(int i=0; i<x; i++) {
            printf("x%d -> ", i+1);
            scanf("%f", &vetSolution[i][0]);
        }

        printf("Valor do erro -> ");
        scanf("%f", &error);

        printf("\nMAtriz Passada\n");
        exibir(Matriz, x, x+1);

        trocarLinha(Matriz, x);

        applyMethod(Matriz, vetSolution, error, x);

    }
    Matriz = Liberacao(Matriz, x);
    return 0;
}

int validarEntrada(){
    int x;
    scanf("%d", &x);
    if(x < 2) {
        printf("\n\nError!!!!\n\n");
        return 0;
    }

    return x;
}

void insulator(float ** M, float ** variables, int TAM) {
    int column = 0;
    for (int i = 0; i < TAM; ++i) {
        for (int j = 0; j <= TAM; ++j) {
            if ( TAM-j != i) {
                if (j == 0) {
                    variables[i][column] = M[i][TAM-j] / M[i][i];
                } else {
                    variables[i][TAM - column] = (M[i][TAM-j] * -1) / M[i][i];
                }
                column++;
            }
        }
        column = 0;
    }
}

float bigger(float ** vet, int TAM) {
    float b = vet[0][0];
    for (int i = 1; i < TAM; ++i) {
        if(modulo(vet[i][0]) > b)
            b = modulo(vet[i][0]);
    }
    return b;
};

void applyMethod(float ** M, float ** vetSoluction, float error, int TAM) {
    float ** variables = Aloca(TAM, TAM),
            ** results = Aloca(TAM, 1),
            ** vetModulos = Aloca(TAM, 1),
            ** vetSoluctionCopy = Aloca(TAM, 1),
            bigger1, bigger2;

    int auxVetSolution;

    insulator(M, variables, TAM);
    do{
        auxVetSolution = 1;

        for (int l = 0; l < TAM; ++l) {
            vetSoluctionCopy[l][0] = vetSoluction[l][0];
        }

        for (int i = 0; i < TAM; ++i) {
            for (int j = 0; j < TAM; ++j) {

                if (j == 0) {
                    results[i][0] = variables[i][0];
                } else {
                    results[i][0] += (variables[i][j] * vetSoluction[auxVetSolution][0]) ;
                    auxVetSolution++;
                    if (i == auxVetSolution) auxVetSolution++;
                }
            }
            vetSoluction[i][0] = results[i][0];
            auxVetSolution = 0;
        }

        for (int k = 0; k < TAM; ++k) {
            vetModulos[k][0] = modulo(vetSoluction[k][0]) - modulo(vetSoluctionCopy[k][0]);
        }
        bigger1 = bigger(vetModulos, TAM);
        bigger2 = bigger(vetSoluction, TAM);
        printf("Opa\n");
    }while (bigger1/bigger2 >= error);

    printf("\nVETOR SOLUÇÂO\n");
    for (int m = 0; m < TAM; ++m) {
        printf("%.4f\n", vetSoluction[m][0]);
    }
}

void trocarLinha(float ** M, int TAM) {
    int howLineChange;
    float v1, v2;
    for(int column=0; column < TAM-1; column++) {
        howLineChange = howChange(M, column, TAM);
        if(howLineChange != column) {
            for (int i = 0; i < TAM+1; i++) {
                v1 = M[column][i];
                v2 = M[howLineChange][i];
                M[column][i] = v2;
                M[howLineChange][i] = v1;
            }
        }
    }
}

float modulo(float n) {
    return n < 0 ? n * -1 : n;
}

int howChange(float ** M, int column, int TAM) {
    float aux = M[column][column];
    int lineWithMaxNumber = column;
    for(int i=column; i<TAM; i++){
        if(modulo(M[i][column])>aux) {
            aux = modulo(M[i][column]);
            lineWithMaxNumber = i;
        }
    }
    return lineWithMaxNumber;
}

float calculoDeterminante(float ** M, int nTrocas, int TAM) {
    float det=1;
    for (int i=0; i<TAM; i++) {
        det *= M[i][i];
    }
    return nTrocas % 2 == 0 ? det : det * -1;
}