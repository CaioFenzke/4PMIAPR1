#define NBTESTS 10000
#define NBCAS 4
#include "vectEx1.h"
#include <stdlib.h>
#include <stdio.h>

// Programme de tests aleatoire
// 3 fois plus d'ajout que de suppression
int main() {
  vect_t t1 = vect_new(2);
  double x;
  int i,j,nb;

  for (j=0; j<NBTESTS; j++) {
    switch(random() % NBCAS) {
      case 0: case 1: case 2:
        x = random() % 100;
        printf("Append de %lf \n: ",x);
        t1=vect_append(x,t1);
        break;
      case 3:
        nb=random()%((t1->actual_size)+1);
        printf("Suppression des %d dernieres valeurs : ",nb);
        t1=vect_remove_nlast(nb,t1);
        break;
    }
    for(i=0; i<(int)t1->actual_size; i++)
      printf("%lf ",t1->data[i]);
    printf("actual_size: %d /// max_size: %d ",t1->actual_size, t1->max_size);
    
    puts("");
  }
  printf("Liberation du tableau\n");
  t1=vect_delete(t1);
}