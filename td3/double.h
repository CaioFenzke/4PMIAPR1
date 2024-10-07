
#ifndef _DOUBLE_H
#define _DOUBLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Affichage d'une chaine de type mystring
void double_fprintf(void* val,FILE* fp);
void double_printf(void* val); 

// Test l'egalite de 2 reels
int double_equal(void* pv1, void* pv2);

// Génération d'un reel aléatoire
void double_random(double* p);

// Clone d'un reel
double* double_new(double val);

void* double_delete(void *data);

#endif