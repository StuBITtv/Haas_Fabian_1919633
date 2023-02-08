#ifndef HA03_LINKEDLISTLIB_H_
#define HA03_LINKEDLISTLIB_H_

#include <stdlib.h>

struct listElem{
    char lastName[50];
    char firstName[50];
    int age;
    struct listElem *nextElem;
};
typedef struct listElem listElement;

int numberInput(size_t maxDigits);

listElement * addListElem(listElement *list);

void printList(const listElement *list);

listElement *delListElem(listElement *list);

void delList(listElement *);

int getLenOfList(const listElement *list);

void saveList(const listElement *list);

listElement *loadList(listElement *list);

void exitFcn(listElement *);

listElement *sortList(listElement *list);

void stringToLower(char *);

#endif
