#ifndef CN_DINAMICALOCATION_H
#define CN_DINAMICALOCATION_H
#include <stdio.h>
#include <stdlib.h>

float **Aloca(int row,int col);
float **preencher(float **Matriz,int row,int col);
void exibir(float **Matriz,int row,int col);
float **Liberacao(float **Matriz,int row);

#endif //CN_DINAMICALOCATION_H
