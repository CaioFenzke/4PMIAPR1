#include "stacks.h"

stacks_t stacks_new(unsigned int n, void (*fprint_data)(void*,FILE*),void* (*delete_data)(void*), int (*equal_data)(void*,void*)) {
    return (stacks_t) vect_new(n, fprint_data, delete_data, equal_data);
} 

stacks_t stacks_delete(stacks_t table) {
    return vect_delete(table);
}

int stacks_is_empty(stacks_t table) {
    return table->actual_size == 0;
}

stacks_t stacks_push(void* e, stacks_t table) {
    return vect_append(e, table);
}

void* stacks_pop(stacks_t table) {
    if (stacks_is_empty(table))
        return NULL;
    void* e = table->data[0];
    vect_remove_at(0, table);
    return e;
}

void* stacks_peek(stacks_t table) {
    return table->data[0];
}

void stacks_printf(stacks_t table) {
    int i;
    for (i=0; i<table->actual_size; i++) {
        table->fprint_data(table->data[i], stdout);
    }
    printf("\n");
}

void stacks_fprintf( stacks_t table,FILE* f) {
    int i;
    for (i=0; i<table->actual_size; i++) {
        table->fprint_data(table->data[i], f);
    }
    printf("\n");
}

