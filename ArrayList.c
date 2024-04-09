
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
void printAll()
 {
  
 for ( int i =0; i < position; i++){
  printf("Nome: %s\n",list[i].name);
  printf("endereco: %s\n",list[i].endereco);
  printf("cpf: %s\n",list[i].cpf);
  printf("telefone: %s\n",list[i].telefone);
  printf("email: %s\n",list[i].email);
  printf("==========================\n");
 }
 }