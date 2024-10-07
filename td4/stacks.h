#ifndef _stacks_H
#define _stacks_H
#include <stdio.h>
#include<assert.h>
#include <stdlib.h>
#include <string.h>

#include "vect.h"

// Une pile est un tableau redimensionnable
typedef vect_t stacks_t;

// Creation d'une pile de n elements
stacks_t stacks_new(unsigned int n,void (*print_data)(void*,FILE*),
      void* (*delete_data)(void*),int (*equal_data)(void*,void*)) ;

// Empiler un element
stacks_t stacks_push(void* e, stacks_t table)  ;

// Depile un element en le retournant, supprime l'element de la pile
void* stacks_pop(stacks_t table);

// Retourne le premier element, sans le supprimer
void* stacks_peek(stacks_t table);

// Pile vide ?
int stacks_is_empty(stacks_t l);

// Affiche la pile
void stacks_printf(stacks_t table);
void stacks_fprintf( stacks_t table,FILE* f);

// Supprime la pile
stacks_t stacks_delete(stacks_t table);
#endif
