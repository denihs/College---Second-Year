#include <stdio.h>

//prototipos das funções
double sen(double x);
double pot(double x, int i);
double fat(int i);
//função princinpal
int main(int argc, char const *argv[])
{
    double x;

    /*fazer um programa que:
        calcule o sen(x) = x^³/3! + x^5/5 - x^7/7 + x^9/9*/
    //entra com o valor
    printf("informe o valor do seno: \n");
    scanf("%lf",&x);
    sen(x);
    return 0;
}
//funções
//função do seno
double sen (double x ){
    //pega  o valor de x
    double fatvalor;//variavel que guarda o valor do fatorial
    double potvalor;//variavel que guarda o valor da potencia
    double valorSeno;
    double valorSenoTotal;
    double valor3, valor5, valor7;
    for (int i = 1; i < 9;)
    {
        if (i > 1)
        {
            potvalor = pot(x,i);// parte da potencia está ok
            fatvalor = fat(i);//fatorial ok
            valorSeno = potvalor/fatvalor;
            printf("valorSeno %lf\n", valorSeno );
            if (i == 3){
                valor3 = valorSeno;
            }else{
                if (i == 5){
                    valor5 = valorSeno;
                }else{
                    if (i == 7){
                        valor7 = valorSeno;
                    }
                }
            }
        }

        i+= 2;
    }
    valorSenoTotal = valor3 + valor5 - valor7;
    printf("o valor do  do seno é %lf\n",valorSenoTotal );
}
//função que calcula o expoente
double pot(double x, int i){
    double potencia =1;
    if (i > 1){
        for (int j = 0 ; j < i; ++j){
            potencia = potencia*x;
        }
        return potencia;
    }
}
//função que calcula o fatorial do numero
double fat(int i){
    double valorFat= 1;
    //parte do fatorial
    for (int j = 1; j < i+1; ++j){
        if (j > 1){
            valorFat = valorFat*j;
        }
    }
    return valorFat;

}