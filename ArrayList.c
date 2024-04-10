
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
  printf("CPF: %lf\n", list[i].cpf);
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

void del(double cpf)
  {
    int index;
    if (position == 0) {
        printf("Lista vazia!\n");
        return;
    }
    if (find(cpf, &index))
    {
        for(int i = index; i < position; i++)
          {
              list[i] = list[i+1];
            }
    position--;
      return;
  }
    printf("CPF nao encontrado!\n");
  } 
   

bool find(double cpf,int *index)
{

  
    for(int i = 0; i < position; i++)
      {
        if (list[i].cpf == cpf )
        {
          *index = i;
          return true;
        }

      
      }
  return false;
}



void print(double cpf)

 {
int index;
 
  if(find (cpf,&index))
  {
  menu(index);
  }
   else
  {
    printf("Cliente nao encontrado!\n");  
  }
 }


void printAll()
 {
  if (position==0)
  {
    printf("Lista vazia!\n");
  }
 for ( int i =0; i < position; i++){
  menu(i);
 }
 }