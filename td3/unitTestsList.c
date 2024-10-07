#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

// Função auxiliar para comparar dois inteiros
int equal_int(void* a, void* b) {
    return (*(int*)a == *(int*)b);
}

// Função de liberação de inteiros
void* delete_int(void *data) {
    if (data != NULL) {
        free(data);
    }
    return NULL;
}

// Função para imprimir inteiros
void fprint_int(void* data, FILE* fp) {
    fprintf(stdout, "%d ", *(int*)data);
}

// Função auxiliar para criar inteiros dinamicamente
int* create_int(int value) {
    int* ptr = malloc(sizeof(int));
    if (ptr == NULL) {
        perror("Error allocating memory");
        exit(1);
    }
    *ptr = value;
    return ptr;
}

int main() {
    printf("// 1. Criação de uma nova lista\n");
    printf("Criando nova lista...\n");
    list_t list = list_new(fprint_int, delete_int, equal_int);
    
    printf("// 2. Verificando se a lista está vazia\n");
    if (list_is_empty(list)) {
        printf("Lista vazia após criação.\n");
    } else {
        printf("Erro: Lista deveria estar vazia.\n");
    }

    printf("// 3. Adicionando elementos no início da lista\n");
    int* num1 = create_int(10);
    printf("Adicionando %d no início da lista.\n", *num1);
    list = list_add_first(num1, list);

    int* num2 = create_int(20);
    printf("Adicionando %d no início da lista.\n", *num2);
    list = list_add_first(num2, list);

    printf("// 4. Verificando o primeiro elemento da lista\n");
    int* first = (int*)list_first(list);
    printf("Primeiro elemento da lista: %d\n", *first);

    printf("// 5. Adicionando elementos no fim da lista\n");
    int* num3 = create_int(30);
    printf("Adicionando %d no fim da lista.\n", *num3);
    list = list_add_last(num3, list);

    printf("// 6. Exibindo o conteúdo da lista\n");
    printf("Lista após adições: ");
    list_printf(list);
    printf("\n");

    printf("// 7. Buscando um elemento na lista\n");
    int* search_num = create_int(30);
    printf("Buscando elemento %d na lista...\n", *search_num);
    link_t found = list_find(search_num, list);
    if (found != NULL) {
        printf("Elemento %d encontrado.\n", *(int*)found->data);
    } else {
        printf("Elemento %d não encontrado.\n", *search_num);
    }
    free(search_num);  // Libera memória da busca (não inserida na lista)

    printf("// 8. Removendo o primeiro elemento da lista\n");
    printf("Removendo o primeiro elemento...\n");
    list = list_del_first(list);
    printf("Lista após remoção do primeiro elemento: ");
    list_printf(list);
    printf("\n");

    printf("// 9. Removendo o último elemento da lista\n");
    printf("Removendo o último elemento...\n");
    list = list_del_last(list);
    printf("Lista após remoção do último elemento: ");
    list_printf(list);
    printf("\n");

    printf("// 10. Removendo um elemento específico\n");
    printf("Removendo elemento %d da lista...\n", *num1);
    list = list_remove(num1, list);
    printf("Lista após remoção do elemento %d: ", *num1);
    list_printf(list);
    printf("\n");

    printf("// 11. Verificando o tamanho da lista\n");
    printf("Tamanho da lista: %lu\n", list_length(list));

    printf("// 12. Liberando toda a lista\n");
    printf("Liberando toda a lista...\n");
    list = list_delete(list);

    return 0;
}
