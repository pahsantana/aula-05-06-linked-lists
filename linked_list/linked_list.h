#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "element.h"

typedef struct LinkedList LinkedList;

LinkedList* list_create();
void list_destroy(LinkedList* list);
void list_insertFirst(LinkedList* list, Element element);
void list_insertAfter(LinkedList* list, int pos, Element element);
void list_print(LinkedList* list);

#endif