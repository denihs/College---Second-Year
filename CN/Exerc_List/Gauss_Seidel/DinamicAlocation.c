#include "DinamicAlocation.h"

/*------------------ALOCAÇÃO DAS MATRIZES A e B--------------------*/
float **Aloca(int row,int col)
{
    int count;
    float **Mat=NULL;
    Mat = (float**) malloc(row*sizeof(float *)) ;
    if(Mat==NULL){printf("Espaco de memoria insuficiente\n"); return NULL;}

    for(count=0;count<row;count++){
        Mat[count]=(float *) malloc(col*sizeof(float));
        if(Mat[count]==NULL){printf("Espaco de memoria insuficiente\n"); return NULL;}
    }
    return(Mat);
}
/*------------------LIBERANDO AS MATRIZES--------------------*/
float **Liberacao(float **Matriz,int row)
{
    int count;
    if(Matriz==NULL){return NULL;}

    for(count=0;count<row;count++){
        free(Matriz[count]);
    }
    free(Matriz);
    return NULL;
}
/*------------------PREENCHIMENTO DAS MATRIZES--------------------*/
float **preencher(float **Matriz,int row,int col)
{
    int i,j,count=0;
    for(i=0;i<row;i++){
        for(j=0;j<col+1;j++){
            if(count == col) {
                printf("Resultado da linha %d--> ", i+1);
                count = -1;
            }else{
                printf("L[%d] C[%d] -> ", i, j);
            }
            scanf("%f", &Matriz[i][j]);
            count++;
        }
    }
    return Matriz;
}
/*------------------EXIBINDO AS MATRIZES--------------------*/
void exibir(float **Matriz,int row,int col)
{
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%.2f ",Matriz[i][j]);
        }
        printf("\n");
    }

}