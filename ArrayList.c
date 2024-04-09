
#include "ArrayList.h"

// variáveis
struct listV *list = NULL;
int position = 0;
int maxSize = 5;


// Funções
void menu(int i)
{
  printf("Nome: %s\n", list[i].name);
  printf("Endereco: %s\n", list[i].endereco);
  printf("CPF: %s\n", list[i].cpf);
  printf("Telefone: %s\n", list[i].telefone);
  printf("Email: %s\n", list[i].email);
}
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

bool print(char *cpf,int *index)
{
  
    for(int i = 0; i < position; i++)
      {
        if (strcmp(list[i].cpf, cpf) == 0)
        {
          *index = i;
          return 1;
        }

      
      }
  return 0;
}




void printAll()
 {
  
 for ( int i =0; i < position; i++){
  menu(i);
 }
 }