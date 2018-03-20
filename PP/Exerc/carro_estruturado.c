#include <stdio.h>

typedef struct {
    char cor[12], marca[10];
    int ano, n_rodas;
} Carro;

int menu(Carro * c);
void fill(Carro * c);
void edit(Carro * c);
void show(Carro * c);

void set_marca(Carro * c);
void set_cor(Carro * c);
void set_ano(Carro * c);

int main() {
    Carro carro;
    int ret;
    do{
        ret = menu(&carro);
    } while (ret);
    return 0;
}

int menu(Carro * c) {
    int op;
    printf("\nInserir = 1\nEditar = 2\nMostrar = 3\nSair = 0\n->> ");
    scanf("%d", &op);
    switch (op) {
        case 1:
            fill(c);
            break;
        case 2:
            edit(c);
            break;
        case 3:
            show(c);
            break;
        case 4:
            return 0;
        default:
            printf("\nOpção invalida\n");
    }
    return 1;
}

void fill(Carro * c) {
    c->n_rodas = 4;

    printf("Marca do carro -> ");
    set_marca(c);

    printf("Cor do carro -> ");
    set_cor(c);

    printf("Ano do carro-> ");
    set_ano(c);
}

void edit(Carro * c) {
    int op;
    printf("\n\nMarca - 1\nCor - 2\nAno - 3\n--> ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            printf("Nova marca-> ");
            set_marca(c);
            break;
        case 2:
            printf("Nova cor-> ");
            set_cor(c);
            break;
        case 3:
            printf("Novo ano-> ");
            set_ano(c);
            break;
        default:
            printf("\n\nOpcao invalida\n");
    }
}

void set_marca(Carro * c) {
    setbuf(stdin, NULL);
    scanf("%11[^\n]", c->marca);
}
void set_cor(Carro * c) {
    setbuf(stdin, NULL);
    scanf("%11[^\n]", c->cor);
}
void set_ano(Carro * c) {
    scanf("%d", &c->ano);
}

void show(Carro * c) {
    printf("\nMarca: %s\n", c->marca);
    printf("Cor: %s\n", c->cor);
    printf("Ano: %d\n", c->ano);
    printf("NUMERO DE RODAS: %d\n", c->n_rodas);
}
