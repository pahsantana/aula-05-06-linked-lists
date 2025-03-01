#include <stdio.h>

#include "linked_list.h"

void test_insert() {
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
}

void test_removeFirst() {
    LinkedList* list = list_create();

    bool res = list_removeFirst(list);
    printf("%s\n", (res) ? "true" : "false");

    list_insertFirst(list, 10);
    list_insertFirst(list, 20);
    list_insertFirst(list, 30);
    list_print(list);

    res = list_removeFirst(list);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);

    res = list_removeFirst(list);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);

    res = list_removeFirst(list);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);

    res = list_removeFirst(list);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);


    list_destroy(list);
}

void test_removeAt() {
    LinkedList* list = list_create();

    bool res = list_removeAt(list, 3);
    printf("%s\n", (res) ? "true" : "false");

    list_insertFirst(list, 10);
    list_insertFirst(list, 20);
    list_insertFirst(list, 30);
    list_print(list);

    res = list_removeAt(list, -1);
    printf("%s\n", (res) ? "true" : "false");
    res = list_removeAt(list, 5);
    printf("%s\n", (res) ? "true" : "false");

    res = list_removeAt(list, 1);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);

    res = list_removeAt(list, 1);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);

    res = list_removeAt(list, 0);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);

    res = list_removeAt(list, 0);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);


    list_destroy(list);
}


void test_printElements() {
    LinkedList* list1 = list_create();
    LinkedList* list2 = list_create();
    list_insertFirst(list1, 5);
    list_insertFirst(list1, 80);
    list_insertFirst(list1, 10);
    list_insertFirst(list1, 40);
    list_insertFirst(list1, 30);

    list_insertFirst(list2, 4);
    list_insertFirst(list2, 3);
    list_insertFirst(list2, 1);

    list_printElements(list1,list2);

    list_destroy(list1);
    list_destroy(list2);
}


void test_equals() {
    LinkedList* list1 = list_create();
    LinkedList* list2 = list_create();
    list_insertFirst(list1, 5);
    list_insertFirst(list1, 4);
    list_insertFirst(list1, 3);
    list_insertFirst(list1, 2);
    list_insertFirst(list1, 1);

    list_insertFirst(list2, 6);
    list_insertFirst(list2, 4);
    list_insertFirst(list2, 3);
    list_insertFirst(list2, 2);
    list_insertFirst(list2, 1);

    bool res = list_equals(list1,list2);
    printf("%s\n", (res) ? "true" : "false");

    list_destroy(list1);
    list_destroy(list2);
}


void test_sorted() {
    LinkedList* list = list_create();
    list_insertFirst(list, 1);
    list_insertFirst(list, 2);
    list_insertFirst(list, 3);
    list_insertFirst(list, 4);
    list_insertFirst(list, 5);
    // list_insertFirst(list, 5);
    // list_insertFirst(list, 4);
    // list_insertFirst(list, 3);
    // list_insertFirst(list, 2);
    // list_insertFirst(list, 1);
    list_isSorted(list);
    // bool res = list_isSorted(list);
    // printf("%d\n", res);

    list_destroy(list);
}

void test_reversed(){
    LinkedList* list = list_create();
    list_insertFirst(list, 1);
    list_insertFirst(list, 2);
    list_insertFirst(list, 3);
    list_insertFirst(list, 4);
    list_insertFirst(list, 5);

    list_printReverse(list);

    list_destroy(list);
}

void test_removeDuplicates(){
    LinkedList* list = list_create();
    list_insertFirst(list, 3);
    list_insertFirst(list, 5);
    list_insertFirst(list, 4);
    list_insertFirst(list, 2);
    list_insertFirst(list, 3);
    list_insertFirst(list, 2);
    list_insertFirst(list, 1);

    list_print(list);

    list_removeDuplicates(list);

    list_print(list);

    list_destroy(list);
}


int main() {
    // test_removeFirst();
    // test_removeAt();
    // test_printElements();
    // test_equals();
    // test_sorted();
    test_removeDuplicates();

    return 0;
}