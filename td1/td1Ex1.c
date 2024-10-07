#include <stddef.h>
#include <cstdio>

typedef struct  {
    double* data  ;     // Les données du tableau
    size_t size;    // La taille maximale
    size_t actual_size;    // La taille actuelle
} * table_t;


// création d'un tableau de n éléments
table_t table_new(int n) {
    table_t ptab;

    // Allocation de la structure
    ptab=calloc(1,sizeof(*ptab));
    ptab->size=n;
    
    // Allocation des données
    if ((ptab->data=calloc(n,sizeof(*(ptab->data))))==NULL) {
        free(ptab);
        return NULL;
    }
    return ptab;
}

//suppression du tableau tab
table_t table_delete(table_t tab) { 
    int i;
    if (tab==NULL) return NULL;
    // A t on passe une fonction de liberation des elements ?
    if (table->delete_data)
    // On libere les elements grace à notre pointeur
        for (i=0; i<tab->actual_size; i++)
            table->delete_data(tab.data[i]);

    // On libere le tableau et la structure allouée
    free(tab->data);
    free(tab);
    return NULL;
}

// affichage du tableau
void table_printf(table_t tab) {
    int i;
    for (i=0; i<tab->size; i++) {
        printf("%d ",tab->data[i]);
    }
    printf("\n");
}

// minimum du tableau
int table_min(table_t tab) {
    int i;
    int min=tab->data[0];
    for (i=1; i<tab->size; i++) {
        if (tab->data[i]<min)
            min=tab->data[i];
    }
    return min;
}

// ajout d'un element en fin de tableau
int table_append(double val, table_t tab) {
    if (tab->actual_size==tab->size) {
        return -1;
    }

    tab->data[tab->actual_size]=val;
    tab->actual_size++;
    return 0;
}

// insertion d'un element en position index dans le tableau
int table_insert_at(double val, int index, table_t tab) {
    int i;
    if (tab->actual_size==tab->size) {
        return -1;
    }

    tab->data[index]=val;
    return 0;
}

// suppression de l'element en position index dans le tableau
int table_remove_at(int index, table_t tab) {
    int i;
    if (index<0 || index>=tab->actual_size) {
        return -1;
    }

    for (i=index; i<tab->actual_size-1; i++) {
        tab->data[i]=tab->data[i+1];
    }
    tab->actual_size--;
    return 0;
}