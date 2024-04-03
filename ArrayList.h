

#ifndef ARRAYLIST_ARRAYLIST_H
#define ARRAYLIST_ARRAYLIST_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Constante
#define MAX_SIZE 50


struct listV
{
char name[MAX_SIZE];
char endereco[MAX_SIZE];
char cpf[MAX_SIZE];
char telefone[MAX_SIZE];
char email[MAX_SIZE];
};
// variáveis
extern int maxSize;
extern struct listV *list;
extern int position;

// protótipos
void init();
void destroy();
void add(struct listV item);
void expand();


#endif //ARRAYLIST_ARRAYLIST_H
