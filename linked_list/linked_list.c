#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    Element element;
    struct Node* next;
} Node;

struct LinkedList {
    Node* head;
};

LinkedList* list_create() {
    LinkedList* list = malloc(sizeof(LinkedList));

    list->head = NULL;

    return list;
}

void list_destroy(LinkedList* list) {
    Node* cur = list->head;

    while (cur != NULL) {
        Node* trash = cur;

        cur = cur->next;
        free(trash);
    }
    free(list);
}

void list_insertFirst(LinkedList* list, Element element) {
    Node* newNode = malloc(sizeof(Node));

    newNode->element = element;
    newNode->next = list->head;
    list->head = newNode;
}

void list_insertAfter(LinkedList* list, int pos, Element element) {
    if (list->head == NULL || pos < 0) {
        list_insertFirst(list, element);
    } else {
        Node* cur = list->head;
        int i = 0;

        while (i < pos && cur->next != NULL) {
            cur = cur->next;
            i++;
        }

        Node* newNode = malloc(sizeof(Node));

        newNode->element = element;
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

void list_print(LinkedList* list) {
    Node* cur = list->head;

    while (cur != NULL) {
        element_print(cur->element);
        cur = cur->next;
        if (cur != NULL) {
            printf(" -> ");
        }        
    }
    printf("\n");
}