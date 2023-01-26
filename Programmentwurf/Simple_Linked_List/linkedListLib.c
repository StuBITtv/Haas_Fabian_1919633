#include <stdio.h>
#include <string.h>
#include "linkedListLib.h"


int numberInput(size_t maxDigits) {
    char *buffer = malloc(maxDigits + 2);

    while (1) {
        scanf("%s", buffer);

        char *numberEnd;
        int number = strtol(buffer, &numberEnd, 10);

        size_t inputLength = strlen(buffer);
        if(numberEnd == &buffer[inputLength]) {
            free(buffer);
            return number;
        }
    }
}

listElement *addListElem(listElement *list) {
    listElement *new = malloc(sizeof(listElement));
    new->nextElem = NULL;

    if (new == NULL) {
        printf("can't reserve storage.\n");
        return NULL;
    }

    /* fill data in new element */
    printf("Please enter last name: \n");
    scanf("%s", new->lastName);

    printf("Please enter first name: \n");
    scanf("%s", new->firstName);

    printf("Please enter age: \n");
    new->age = numberInput(4);


    if(!list) {
        return new;
    }

    listElement *previous = list;

    while (previous->nextElem != NULL) {
        previous = previous->nextElem;      // get last elem in list
    }

    previous->nextElem = new;       // add new to the end of list

    return list;
}

void printList(const listElement *list) {
    if (list == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\ncurrent list:\n\n");

    int index = 0;
    while (list) {
        printf("%d.", ++index);
        printf("\t last name: %s\n", list->lastName);
        printf("\t first name: %s\n", list->firstName);
        printf("\t age: %d\n", list->age);

        list = list->nextElem;
    }
}

listElement *delListElem(listElement *list) {
    /* YOUR CODE HERE */
    /* ---------------*/

    printf("\n>> delListElem fcn is tbd.\n\n");

    return list;
}

void delList(listElement *list) {
    /* YOUR CODE HERE */
    /* ---------------*/

    printf("\n>> getLenOfList fcn is tbd.\n\n");
}

int getLenOfList(const listElement *list) { // we use this for save list fcn
    int counter = 0;

    while (list) { // get last elem in list
        list = list->nextElem;
        ++counter;
    }

    return counter;
}

void saveList(const listElement *list) {
    /* YOUR CODE HERE */
    /* ---------------*/

    printf("\n>> saveList fcn is tbd.\n\n");
}

listElement *loadList(listElement *list) {
    /* YOUR CODE HERE */
    /* ---------------*/

    printf("\n>> loadList fcn is tbd.\n\n");

    printf("loading data will be append to current list...\n");
    printList(list); // show loaded list

    return list;
}

void exitFcn(listElement *list) {
    printf("\n>> exitFcn fcn is tbd.\n\n");
}

listElement *sortList(listElement *list) {
    printf("\n>>sortList fcn is tbd.\n\n");

    return list;
}

void stringToLower(char *string) {
    printf("\n>>stringToLower fcn is tbd.\n\n");
}
