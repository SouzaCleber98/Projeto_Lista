
#include "ArrayList.h"

// variáveis
struct listV *list = NULL;
int position = 0;
int maxSize = 5;


// Funções
void init()
{
    list = malloc(maxSize * sizeof(struct listV));
    if(!list)
    {
        printf("Erro de alocacao de memoria!\n");
        exit(EXIT_FAILURE);
    }
}

void destroy()
{
    free(list);
}

void add(struct listV item) {
    if (position == maxSize) {
        expand();
    }
    list[position] = item;
    position++;
}





void expand()
{

    struct listV *aux;
    int novoTamanho;

    printf("Expandindo...\n");

    novoTamanho = maxSize + 3;
    aux = malloc(novoTamanho * sizeof(struct listV));
    if(!aux)
    {
        printf("Erro de alocacao de memoria\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < maxSize; i++)
    {
        aux[i] = list[i];
    }
    maxSize = novoTamanho;
    free(list);
    list = aux;
}
