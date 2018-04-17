#include <stdio.h>
#include <stdlib.h>
#include "DinamicAlocation.h"

int validarEntrada();
int setTrianguloSuperior(float ** M, int x);
int trocarLinha(float ** M, int TAM, int n);
float calculoDeterminante(float ** M, int nTrocas, int TAM);
float modulo(float n);
int howChange(float ** M, int n, int TAM);

int main() {
    float **Matriz, determinante;
    int trocas;
    printf("Informe a dimensão da matriz->> ");
    int x = validarEntrada();
    if (x) {
        Matriz = Aloca(x,x);
        Matriz = preencher(Matriz, x,x);
        printf("\nMAtriz Passada\n");
        exibir(Matriz, x,x);
        trocas = setTrianguloSuperior(Matriz, x);
        determinante = calculoDeterminante(Matriz, trocas, x);
        printf("\nMAtriz Final\n");
        exibir(Matriz, x,x);
        printf("\nDeterminante\n");
        printf("%.4f\n\n",determinante);
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

int setTrianguloSuperior(float ** M, int x) {
    int n_troca=0;
    float m, L;
    for (int pivo = 0; pivo < x - 1; pivo++) {
        if (trocarLinha(M, x, pivo)) { n_troca++; }
        for (int i = pivo; i < x-1; i++) {
            if(M[pivo][pivo]!=0){
                m = (M[i + 1][pivo] / M[pivo][pivo]) * -1;
                for (int j = pivo; j < x; j++) {
                    L = m * M[pivo][j] + M[i + 1][j];
                    M[i + 1][j] = L;
                }
            }

        }
    }
    return n_troca;
}
int trocarLinha(float ** M, int TAM, int n) {
    int howLineChange;
    int CONTROLE = 1;
    if(M[n][n]==0){
        howLineChange = howChange(M, n, TAM);
        if(howLineChange)
            CONTROLE  = howLineChange;
    }

    float v1, v2;
    float n1 = modulo(M[n][n]),
          n2 = modulo(M[n+CONTROLE][n]);
    if(n1 < n2){
        for(int i=0; i < TAM; i++) {
            v1 = M[n][i];
            v2 = M[n + CONTROLE][i];
            M[n][i] = v2;
            M[n + CONTROLE][i] = v1;
        }
        return 1;
    }
    return 0;
}

float modulo(float n) {
    return n < 0 ? n * -1 : n;
}

int howChange(float ** M, int n, int TAM) {
    for(int i=1; i+n<TAM; i++){
        if(M[n+i][n]!=0)
            return i;
    }
    return 0;
}

float calculoDeterminante(float ** M, int nTrocas, int TAM) {
    float det=1;
    for (int i=0; i<TAM; i++) {
        det *= M[i][i];
    }
    return nTrocas % 2 == 0 ? det : det * -1;
}