#include "vectEx1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

vect_t vect_new(unsigned int n) {
    vect_t vect;

    if ((vect=malloc(sizeof(double))) == NULL)
        return NULL;

    vect->max_size = n;
    vect->actual_size=0;

    if ((vect->data=calloc(n,sizeof(double))) == NULL) {
        free(vect);
        return NULL;
    }

    return vect;
}

vect_t vect_append(double e, vect_t table) {
    if (table==NULL) return NULL;
    if (table->actual_size == table->max_size-1) {
        table->max_size *= 2;
        table->data=realloc(table->data, table->max_size*sizeof(double));
    }
    table->data[table->actual_size]=e;
    table->actual_size++;
    return table;
}

vect_t vect_remove_nlast(int n, vect_t table) {
    table->actual_size -= n;

    if (table->actual_size != 0 && table->actual_size <= table->max_size / 3) {
        table->max_size /= 2;
        table->data=realloc(table->data, table->max_size*sizeof(double));
    }
    return table;
}

vect_t vect_delete(vect_t table){
    if (table==NULL) return NULL;
    
    free(table->data);
    free(table);
    return NULL;
}
