#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct list {
    int line;
    struct list * prox;
};
typedef struct list List;

struct tree {
    struct tree *left;
    struct tree *right;
    char word[20];
    int height;
    List *list;
};
typedef struct tree Tree;

FILE* open(char* nome_arq, char* c);
void close( FILE* f, char* nome_arq );
void lower_string(char *s);
Tree * insert(Tree *node, char *word, int nLine);
int empty(Tree * head);
void printOnFile(Tree * head, FILE * file);

int main() {
    char init[30];
    char init2[30];
    char x[1000];
    char * word;
    int nLine = 1;
    int choice;

    printf("Qual dos arquivos abrir?\n1 - brasil\n2 - faroeste\n3 - teste\n-> ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            strcpy(init, "text/brasil.txt");
            strcpy(init2, "text/brasils.txt");
            break;
        case 2:
            strcpy(init, "text/faroeste.txt");
            strcpy(init2, "text/faroestes.txt");
            break;
        case 3:
            strcpy(init, "text/teste.txt");
            strcpy(init2, "text/testes.txt");
            break;
        default:
            printf("\nEscolha invalida\n");
            exit(1);
    }

    FILE *file = open(init, "r");

    Tree *tree = (Tree*) malloc(sizeof(Tree));
    tree->right = tree->left = NULL;
    tree->list = (List *) malloc(sizeof(List));
    tree->list->prox = NULL;


    while (fgets( x, sizeof(x), file) != NULL) {
        word = strtok (x," ,.-!");
        while (word != NULL)
        {
            lower_string(word);
            if (strlen(word) > 2) {
                tree = insert(tree, word, nLine);
            }

            word = strtok (NULL, " ,.-!");
        }
        nLine++;
    }



    FILE *fileToSave = open(init2, "w");

    printOnFile(tree, fileToSave);

    close(file, init);
    close(fileToSave, init2);
    printf("\nTudo concluido com sucesso!\n");
    return 0;
}

//objetivo: Abrir arquivos para consulta, escrita etc..
//parametros: O caminho e nome do arquivo terá  e  o modo de abertura
//retorno: Retorna o endereço do arquivo na memoria
FILE* open(char* nome_arq, char* c)
{
    FILE* pfile;
    if ( ( pfile = fopen(nome_arq, c) ) == NULL ){
        printf("\n\n\t\033[31mFALHA AO ABRIR O ARQUIVO %s\033[m\n\n", nome_arq);
        exit(1);
    }
    return(pfile);
}

//objetivo: Fechar os arquivos abertos
//parametros: O enderço do arquivo aberto e o nome/caminho do arquivo
//retorno: Sem retorno
void close( FILE* f, char* nome_arq )
{
    if( fclose(f) == EOF ){
        printf("\n\n\t\033[31mFALHA AO FECHAR O ARQUIVO %s\033[m\n\n", nome_arq);
        exit(1);
    }
}

//Insere o numero da linha que a palavra se encontra
void insertNumberLine (int x, List *p) {
    List *nova = (List *) malloc(sizeof(List));
    List *last;

    for(last = p; last->prox != NULL; last = last->prox);

    nova->line = x;
    nova->prox = NULL;
    last->prox = nova;
}

//Imprime a lista com os numeros de linhas de cada Nó
void showNumbersLine(List * n, FILE * file) {
    for(List* i = n ; i->prox != NULL; i = i->prox) {
        fprintf(file, "%d", i->prox->line);
        if(i->prox->prox != NULL) {
            fprintf(file, ", ");
        }
    }
}

//Encontra o menor nó dada uma raiz
Tree* find_min( Tree* t )
{
    if( t == NULL )
        return NULL;
    else if( t->left == NULL )
        return t;
    else
        return find_min( t->left );
}

// Encontra o maior nó de uma raiz
Tree* find_max( Tree* t )
{
    if( t != NULL )
        while( t->right != NULL )
            t = t->right;

    return t;
}

//Retorna a altura da arvore
int height( Tree* n )
{
    if( n == NULL )
        return -1;
    else
        return n->height;
}


//Retornar o maior valor entre dois inteiros
int max( int l, int r)
{
    return l > r ? l: r;
}


//Faz uma rotação simples a esquerda
Tree* singleRotateWithLeft( Tree* k2 )
{
    Tree* k1 = NULL;

    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
    k1->height = max( height( k1->left ), k2->height ) + 1;
    return k1;
}

//Executa uma rotação simples a direita
Tree* singleRotateWithRight( Tree* k1 )
{
    Tree* k2;

    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
    k2->height = max( height( k2->right ), k1->height ) + 1;

    return k2; 
}

//Rotação dupla a esquerda
Tree* doubleRotateWithLeft( Tree* k3 )
{
    k3->left = singleRotateWithRight( k3->left );

    return singleRotateWithLeft( k3 );
}

//Rotação dupla a direita
Tree* doubleRotateWithRight( Tree* k1 )
{
    k1->right = singleRotateWithLeft( k1->right );

    return singleRotateWithRight( k1 );
}

//Função para inserir novo nó
Tree * insert(Tree *node, char *word, int nLine) {
    if (node == NULL) {
        node = (Tree*) malloc(sizeof(Tree));

        strcpy(node->word, word);
        node->height = 0;
        node->right = node->left = NULL;

        node->list = (List *) malloc(sizeof(List));
        node->list->prox = NULL;
        insertNumberLine(nLine, node->list);

    } else if (strcmp(node->word, word) > 0) {
            node->left = insert(node->left, word, nLine);
            if( height( node->left ) - height( node->right ) == 2 )
                if( strcmp(node->left->word, word) > 0 )
                    node = singleRotateWithLeft( node );
                else
                    node = doubleRotateWithLeft( node );

    } else if (strcmp(node->word, word) < 0) {
            node->right = insert(node->right, word, nLine);
            if( height( node->right ) - height( node->left ) == 2 )
                if( strcmp(node->right->word, word) < 0 )
                    node = singleRotateWithRight( node );
                else
                    node = doubleRotateWithRight( node );
    } else {
        insertNumberLine(nLine, node->list);
    }
    node->height = max( height( node->left ), height( node->right ) ) + 1;
    return node;
}

//Imprimir as palavras de forma ordenada
void printOnFile(Tree * head, FILE * file) {
    if(!empty(head) && strlen(head->word)) {
        printOnFile(head->left, file);

        fprintf(file, "%s ", head->word);
        showNumbersLine(head->list, file);
        fprintf(file, "\n");
        
        printOnFile(head->right, file);
    }
}

//Checar se a arvore esta varia
int empty(Tree * head) {
    if (head == NULL)
        return 1;
    return 0;
}

//Colocar uma string totalmente em lowercase
void lower_string(char *s) {
    int c = 0;

    while (s[c] != '\0') {
        if (s[c] >= 'A' && s[c] <= 'Z') {
            s[c] = s[c] + 32;
        }
        c++;
    }

}
