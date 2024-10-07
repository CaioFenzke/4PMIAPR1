#include "stacks.h"
#include "double.h"

int main() {
    // Pile de double
  stacks_t l1=stacks_new(2,double_fprintf,double_delete,double_equal);
  double* pv;
  printf("Ajout de 10,20,30,40,50,60,70 : \n");
  l1=stacks_push(double_new(10),l1);
  l1=stacks_push(double_new(20),l1);
  pv=double_new(30); l1=stacks_push(pv,l1);
  pv=double_new(40); l1=stacks_push(pv,l1);
  l1=stacks_push(double_new(50),l1);
  l1=stacks_push(double_new(60),l1);
  l1=stacks_push(double_new(70),l1);

  stacks_printf(l1);

  pv =stacks_pop(l1);
  printf("Defiler :%lf\n",*pv);
  // Pensez a liberer les elements apres utilisation
  double_delete(pv);
  stacks_printf(l1);

  pv =stacks_pop(l1);
  printf("Defiler :%lf\n",*pv);
  // Pensez a liberer les elements apres utilisation
  double_delete(pv);
  stacks_printf(l1);

  printf("Liberation de la queuee\n");
  l1=stacks_delete(l1);

  return EXIT_SUCCESS;
}