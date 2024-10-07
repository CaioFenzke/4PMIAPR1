#include "vectEx2.h"
#include "time.h"

#define NBTESTS 1000
#define NBCAS 3

double abs_double(double a, double b) {
    if (a>b) {
        return a-b;
    }
    return b-a;
}

int equal_double(void* a, void* b) {
    int i;
    //i=calloc(1,sizeof(int));
    double *c;
    double *d;
    c=(double*)a;
    d=(double*)b;
    if (abs_double(*c,*d)<=1E-9) {
        i=1;
        return i;
    }
    i=0;
    return i;
}

// Fonction de liberation des réels
void* double_delete(void *data) {
  double* p = (double*)data;
  free(p);
  return NULL;
}

// Programme de tests aleatoire
// 3 fois plus d'ajout que de suppression
int main() {
  vect_t t1 = vect_new(2,NULL,double_delete,&equal_double);
  int i,j,nb;
  double *px;
  px=calloc(1,sizeof(double));
    srand( time(NULL) );
  for (j=0; j<NBTESTS; j++) {
    switch(random() % NBCAS) {
      case 0: 
        if(t1->actual_size==0) break;
        nb=random()%(t1->actual_size);
        printf("Suppression de valeur en position %d \n",nb);
        t1=vect_remove_at(nb,t1);
        break;
      case 1: 
        px= malloc(sizeof(*px));
        *px = random() % 100;
        printf("Recherce de l'element: %.2lf \n",*px);
        int pos = vect_find(px,t1); 
        if (pos != -1){
            printf("Element %.2lf trouvé à la position %d \n",*px, pos);
            break;
        }
        printf("Element pas trouvé \n");
        break;
      case 2:
        px= malloc(sizeof(*px));
        *px = random() % 100;
        printf("Append de: %.2lf \n",*px);
        t1=vect_append(px,t1);
        break;
    }
    for(i=0; i<t1->actual_size; i++){
        px=(double*)t1->data[i];
        printf("%.2lf ",*px);
    }
    printf("actual_size: %d /// max_size: %d ",t1->actual_size, t1->max_size);
    puts("");
  }
  printf("Liberation du tableau\n");
  t1=vect_delete(t1);
}