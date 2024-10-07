#include "queue.h"

queue_t queue_new(void (*fprint_data)(void*,FILE*),void* (*delete_data)(void*), int (*equal_data)(void*,void*)) {
    return list_new(fprint_data, delete_data, equal_data);
}

int queue_is_empty(queue_t l) {
    return list_is_empty(l);
}

void* queue_first(queue_t l) {
    return list_first(l);
}

queue_t queue_enqueue(void* e, queue_t l) {
    return list_add_last(e, l);
}

void* queue_dequeue(queue_t l ) {
    if (list_is_empty(l))
        return NULL;
    void* e = list_first(l);
    l->data = l->data->next;
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
    return (l);
}