#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    Element element;
    struct Node* next;
} Node;

struct LinkedList {
    Node* head;
    int size;
};

LinkedList* list_create() {
    LinkedList* list = malloc(sizeof(LinkedList));

    list->head = NULL;
    list->size = 0;

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
    list->size++;
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
        list->size++;
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

bool list_removeFirst(LinkedList* list) {
    if (list->head == NULL) {
        return false;
    }

    Node* trash = list->head;

    list->head = list->head->next;
    free(trash);
    list->size--;

    return true;
}

bool list_removeAt(LinkedList* list, int pos) {
    // caso 0: posicao invalida
    if (pos < 0 || pos >= list->size) {
        return false;
    }

    // caso 1: lista vazia
    if (list == NULL) {
        return false;
    }

    // caso 2: remocao na cabeca
    if (pos == 0) {
        return list_removeFirst(list);
    } else { // caso 3: remocao na cauda
        Node* prev = list->head;
        int i = 0;

        while (i < pos - 1) {
            prev = prev->next;
            i++;
        }

        Node* trash = prev->next;

        prev->next = prev->next->next;
        free(trash);  
        list->size--;

    }

    return true;    
}

void list_printElements(LinkedList* l1, LinkedList* l2) {
    Node* cur = l1->head;
    int pos = 0;
    while (cur != NULL) {
        Node* cur2 = l2->head;
        while (cur2 != NULL) {
            if (cur2->element == pos) {
                element_print(cur->element);
                printf(" ");
                break; 
            }
            cur2 = cur2->next;
        }
        pos++;
        cur = cur->next;
    }
    printf("\n");
}

bool list_equals(LinkedList* l1, LinkedList* l2){
    Node* cur = l1->head;
    Node* cur2 = l2->head;
    if (cur == NULL || cur2 == NULL) {
        return false;
    }
    while (cur != NULL && cur2 != NULL) {
        if(cur->element != cur2->element){
            return false;
        }
        cur2 = cur2->next;
        cur = cur->next;
    }
    return true;
}

int list_isSorted(LinkedList* l) {
    Node* cur = l->head;

    if (cur == NULL || cur->next == NULL) {
        return 1; 
    }

    int ascending = 1; 
    int descending = 1; 
    while (cur->next != NULL) {
        if (cur->element > cur->next->element) {
            ascending = 0;
        } else if (cur->element < cur->next->element) {
            descending = 0; 
        }
        if (!ascending && !descending) {
            return 0; 
        }
        
        cur = cur->next;
    }

    if (ascending) {
        return 1;
    } else if (descending) {
        return 2;
    } else {
        return 0;
    }
}

// void list_printReverseHelper(Node* cur) {
//     if (cur == NULL) {
//         return; // Base case: reached the end of the list
//     }
//     list_printReverseHelper(cur->next);
//     // Print the element of the current node after all subsequent nodes have been printed
//     element_print(cur->element);
//     printf(" ");
// }

// void list_printReverse(LinkedList* l) {
//     list_printReverseHelper(l->head);
//     printf("\n");
// }

void list_printReverse(LinkedList* l) {
    if (l->head == NULL) {
        return; 
    }

    Node* stack = NULL;
    Node* cur = l->head;

    while (cur != NULL) {
        Node* temp = cur;
        cur = cur->next;
        temp->next = stack;
        stack = temp;
    }

    while (stack != NULL) {
        element_print(stack->element);
        stack = stack->next;
        if (stack != NULL) {
            printf(" -> ");
        }
    }
    printf("\n");
}

LinkedList* reverse(LinkedList* list) {
    LinkedList* reversedList = list_create();
    Node* current = list->head;
    while (current != NULL) {
        Element element = current->element;
        list_insertFirst(reversedList, element); 
        current = current->next;
    }
    return reversedList;
}