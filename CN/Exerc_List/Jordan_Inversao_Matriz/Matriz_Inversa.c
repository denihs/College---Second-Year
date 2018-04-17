#include <stdio.h>
#include <stdlib.h>
#include "DinamicAlocation.h"

int validarEntrada();
int setMatrizInversa(float ** M, int x);
void divisoesSucessivas(float ** M, int TAM);
int trocarLinha(float ** M, int TAM, int n);

int main() {
    float **Matriz, determinante;
    int trocas;
    printf("Informe a dimensão da matriz->> ");
    int x = validarEntrada();
    if (x) {
        Matriz = Aloca(x,x*2);
        Matriz = preencher(Matriz, x,x);

        printf("\nMAtriz Passada\n");
        exibir(Matriz, x,x);
        setMatrizInversa(Matriz, x);
        divisoesSucessivas(Matriz, x);

        printf("\nMAtriz Final\n");
        exibir(Matriz, x,x*2);

        printf("\nMAtriz Inversa\n");
        exibirInversa(Matriz, x,x*2);
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

int setMatrizInversa(float ** M, int x) {
    int n_troca=0;
    float m, L;
    for (int pivo = 0; pivo < x ; pivo++) {
        if (trocarLinha(M, x, pivo)) { n_troca++; }
        for (int linha = 0; linha < x; linha++) {
            if(M[pivo][pivo]!=0){
                if(linha != pivo){
                    m = (M[linha][pivo] / M[pivo][pivo]) * -1;
                    for (int coluna = pivo; coluna < x*2; coluna++) {
                        L = m * M[pivo][coluna] + M[linha][coluna];
                        M[linha][coluna] = L;
                    }
                }
            }

        }
    }
    return n_troca;
}

void divisoesSucessivas(float ** M, int TAM) {
    float divisor;
    for (int linha = 0; linha < TAM; linha++) {
            divisor = M[linha][linha];
            for (int coluna = 0; coluna < TAM*2; coluna++) {
                if(M[linha][coluna] != 0){
                    M[linha][coluna] /= divisor;
                }
            }
    }
}

int trocarLinha(float ** M, int TAM, int n) {
    float v1, v2;

    if(M[n][n]==0){
        for(int i=0; i < TAM*2; i++) {
            v1 = M[n][i];
            v2 = M[n + 1][i];
            M[n][i] = v2;
            M[n + 1][i] = v1;
        }
        return 1;
    }
    return 0;
}

