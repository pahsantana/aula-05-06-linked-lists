#include <stdio.h>

#include "linked_list.h"

int main() {
    LinkedList* list = list_create();

    list_insertFirst(list, 10);
    list_insertFirst(list, 20);
    list_insertFirst(list, 30);

    list_print(list);

    list_insertAfter(list, 1, 40);
    list_insertAfter(list, -1, 50);
    list_insertAfter(list, 25, 60);
    list_insertAfter(list, 0, 70);

    list_print(list);

    list_destroy(list);

    return 0;
}