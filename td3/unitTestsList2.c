
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include "double.h"
#include "mystring.h"
// #include "complex.h"

int main() {
    // Liste de réels : pas de liberation car pas d'allocation d'un reel
    list_t l1=list_new(double_fprintf,double_delete,double_equal);
    // Liste de chaines : allocation d'une chaine
    list_t l2=list_new(mystring_fprintf,mystring_delete,mystring_equal);

    // Un pointeur sur maillon pour récupérer les valeurs avec find et lookup
    link_t p;

    // Liste de double
    // Ajout en tete avec la fonction de base
    double* pv;
    printf("Ajout de 10,20,30,40,50,60,70 : \n");
    l1=list_add_first(double_new(10),l1);
    l1=list_add_first(double_new(20),l1);
    pv=double_new(30); l1=list_add_first(pv,l1);
    pv=double_new(40); l1=list_add_first(pv,l1);
    l1=list_add_first(double_new(50),l1);
    l1=list_add_first(double_new(60),l1);
    l1=list_add_first(double_new(70),l1);
    printf("Affichage par list_type_printf :\n");
    list_printf(l1);
    printf("Affichage par visiteur simple \n");
    list_simple_visit(l1,double_fprintf,stdout);
    puts("");
    double y=20;
    printf("Recherche de %lf : ",y);
    if (list_lookup(&y,l1, double_equal)!=NULL) printf("%lf est dans la liste\n",y);
    else printf("%lf n'est pas dans la liste\n",y);
    y=100;
    printf("Recherche de %lf : ",y);
    if (list_lookup(&y,l1, double_equal)!=NULL) printf("%lf est dans la liste\n",y);
    else printf("%lf n'est pas dans la liste\n",y);
    y=60;
    printf("Recherche avec find : %lf",y);
    p=list_find(&y,l1);
    if (p) printf("%lf est dans la liste\n",y);
    else printf("%lf n'est pas dans la liste\n",y);
    printf("Liberation de la liste\n");
    l1=list_delete(l1);


    // Liste de pointeurs vers des chaines de caracteres non partagees;
    // L'utilisateur alloue les chaines, qui seront liberees aussi par
    // cet utilisateur lors de la liberation de liste
    mystring s,s1;
    printf("Ajout de chaine1,2,3,4 : \n");
    // Allocation dynamique d'une chaine (par strdup) et ajout
    s=strdup("chaine1");  l2=list_add_first(s, l2);
    l2=list_add_first(strdup("chaine2"), l2);
    s1=s=strdup("chaine3"); l2=list_add_first(s, l2);
    l2=list_add_first(strdup("chaine4"), l2);
    // Affichage
    list_printf(l2);
    s=strdup("chaine1");
    printf("Recherche par lookup et equal de la valeur %s pointee par %p : ",s,s);
    if (list_lookup(s, l2,  mystring_equal)!=NULL) printf("%s est dans la liste\n",s);
    else printf("%s n'est pas dans la liste\n",s);
    printf("Recherche par find de la valeur %s pointee par %p :",s,s);
    if (list_find(s, l2)!=NULL) printf("%s est dans la liste\n",s);
    else printf("%s n'est pas dans la liste\n",s);
    s=strdup("chaine6");
    printf("Recherche par lookup et equal de la valeur %s pointee par %p :",s,s);
    if (list_lookup(s, l2,  mystring_equal)!=NULL) printf("%s est dans la liste\n",s);
    else printf("%s n'est pas dans la liste\n",s);

    // Suppression du premier maillon : la chaine est libérée par delete_data
    printf("Suppression du premier maillon : ");
    l2=list_del_first(l2);
    list_printf(l2);
    printf("Suppression du premier maillon : ");
    l2=list_del_first(l2);
    list_printf(l2);
    l2=list_del_first(l2);
    printf("Suppression du premier maillon : ");
    list_printf(l2);
    // liberation de toute la liste
    // et liberation des chaines allouees
    l2=list_delete(l2);

    // Liste de pointeurs vers des chaines de caracteres partagees;
    // L'utilisateur N'alloue PAS les chaines, qui NE doivent PAS etre liberees
    // par cet utilisateur lors de la liberation de liste si ces chaines sont
    // encore utilisees
    printf("Ajout de chaine constantes dnas la liste.\n"
    "Attention, les chaines constantes et identiques sont partagées et ont la meme adresse\n ");
    s=strdup("chaine5"); l2=list_add_first(s, l2);
    s=strdup("chaine4"); l2=list_add_first(s, l2);
    s=strdup("chaine3"); l2=list_add_first(s, l2);
    s=strdup("chaine2"); l2=list_add_first(s, l2);
    // list_fprintf(l2,mystring_printf);
    list_printf(l2);

    s=strdup("chaine4");
    printf("Recherche avec find (pointeur egaux) : ");
    p=list_find(s,l2);
    if (p) printf("%s est dans la liste\n",s);
    else printf("%s n'est pas dans la liste car on a fait un strdup pour la chaine a chercher\n",s);
    free(s);

    s=strdup("chaine4");
    printf("Recherche avec find (pointeur egaux) : ");
    p=list_find(s,l2);
    if (p) printf("%s est dans la liste\n",s);
    else printf("%s n'est pas dans la liste\n",s);

    // pas de liberation des chaines, donc 2ieme parametre de list_delete est NULL
    l2=list_delete(l2);
    if (list_is_empty(l2)) printf("Liste vide\n");
    return EXIT_SUCCESS;
}