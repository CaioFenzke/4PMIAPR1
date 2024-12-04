#include <stdio.h>
#include "hashvset.h"
#include "../td4/double.h"

unsigned int fhashage(void* e) {
    return *(double*)e;
}

int main() {
	// Pile de double
	hashvset_t hs1=hashvset_new(4,fhashage,double_fprintf,double_delete,double_equal);
	hashvset_fprintf(hs1, stdout);
	double* pv;
	printf("Ajout de 1,2,3,4,5,6,7 : \n");
	hashvset_put(double_new(0),hs1);
	hashvset_put(double_new(10),hs1);
    hashvset_put(double_new(2),hs1);
	pv=double_new(1);
    hashvset_put(pv,hs1);
	hashvset_fprintf(hs1, stdout);
	hashvset_put(double_new(5),hs1);
	hashvset_put(double_new(6),hs1);
	hashvset_put(double_new(7),hs1);

	hashvset_fprintf(hs1, stdout);

	printf("Defiler :%lf\n",*pv);
	hashvset_remove_key(pv, hs1);

	double_delete(pv);
	hashvset_fprintf(hs1, stdout);

    pv=double_new(3);
	hashvset_remove_key(pv, hs1);
	printf("Defiler :%lf\n",*pv);
	// Pensez a liberer les elements apres utilisation
	double_delete(pv);
	hashvset_fprintf(hs1, stdout);

	printf("Liberation de la queuee\n");
	hs1=hashvset_delete(hs1);
    free(hs1);

	return EXIT_SUCCESS;
}