#include "queue.h"
#include "double.h"

int main() {
    // file de double
    // Ajout en tete avec la fonction de base
  queue_t l1=queue_new(double_fprintf,double_delete,double_equal);
  double* pv;
  printf("Ajout de 10,20,30,40,50,60,70 : \n");
  l1=queue_enqueue(double_new(10),l1);
  l1=queue_enqueue(double_new(20),l1);
  pv=double_new(30); l1=queue_enqueue(pv,l1);
  pv=double_new(40); l1=queue_enqueue(pv,l1);
  l1=queue_enqueue(double_new(50),l1);
  l1=queue_enqueue(double_new(60),l1);
  l1=queue_enqueue(double_new(70),l1);
  if (queue_lookup(pv,l1)) printf("%lf est dans la liste\n",*pv);
  else printf("%lf n'est pas dans la liste\n",*pv);
  printf("Affichage par queue_type_printf :\n");
  queue_printf(l1);

  pv =queue_dequeue(l1);
  printf("Defiler :%lf\n",*pv);
  // Pensez à liberer les elements apres utilisation.
  double_delete(pv);
  queue_printf(l1);

  pv =queue_dequeue(l1);
  printf("Defiler :%lf\n",*pv);
  // Pensez à liberer les elements apres utilisation.
  double_delete(pv);
  queue_printf(l1);

  printf("Liberation de la queuee\n");
  l1=queue_delete(l1);
  free(l1);

  return EXIT_SUCCESS;
}