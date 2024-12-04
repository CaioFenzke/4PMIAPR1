#include "queue.h"

queue_t queue_new(void (*fprint_data)(void*,FILE*),void* (*delete_data)(void*), int (*equal_data)(void*,void*)) {
    return list_new(fprint_data, delete_data, equal_data);
}

int queue_is_empty(queue_t l) {
    return list_is_empty(l);
}

void* queue_first(queue_t l) {
    if (queue_is_empty(l))
        return NULL;
    return list_first(l);
}

queue_t queue_enqueue(void* e, queue_t l) {
    l = list_add_last(e, l);

    link_t current_link = l->data;

    for (int i=0; i<l->size-1; i++) {
        current_link = current_link->next;
    }

    current_link->next = l->data;
    return l;
}

void* queue_dequeue(queue_t l ) {
    if (list_is_empty(l))
        return NULL;
    void* e = list_first(l);
    link_t link = l->data;
    l->data = l->data->next;
    free(link);
    l->size--;
    return e;
}

size_t queue_length(queue_t l) {
    return list_length(l);
}

void queue_printf(queue_t l) {
    list_printf(l);
}

queue_t queue_delete(queue_t l) {
    l=list_delete(l);
    return l;
}

int queue_lookup(void* elem, queue_t l) {
    return (list_lookup(elem, l, l->equal_data) != NULL);
}