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
        if (numberEnd == &buffer[inputLength]) {
            free(buffer);
            return number;
        }
    }
}

listElement *addListElem(listElement *list) {
    listElement *new = malloc(sizeof(listElement));
    new->nextElem = NULL;

    if (new == NULL) {
        printf("can't reserve storage.\n\n");
        return NULL;
    }

    /* fill data in new element */
    printf("Please enter last name: \n");
    scanf("%s", new->lastName);

    printf("Please enter first name: \n");
    scanf("%s", new->firstName);

    printf("Please enter age: \n");
    new->age = numberInput(4);


    if (!list) {
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
        printf("List is empty.\n\n");
        return;
    }

    printf("current list:\n\n");

    int index = 0;
    while (list) {
        printf("%d.", ++index);
        printf("\t last name: %s\n", list->lastName);
        printf("\t first name: %s\n", list->firstName);
        printf("\t age: %d\n", list->age);

        list = list->nextElem;
    }

    printf("\n");
}

static size_t getMaximalDigits(size_t maxNumber) {
    size_t digits = 1;

    while (maxNumber > 10) {
        ++digits;
        maxNumber /= 10;
    }

    return digits;
}

static int listElementPicker(listElement *list) {
    if (!list) {
        printf("The list is already empty.\n\n");
        return -1;
    }

    printList(list);
    printf("Which element from the above do you want to delete?\n");

    int listLength = getLenOfList(list);
    int choice = numberInput(getMaximalDigits(listLength) + 40);

    if (choice > listLength) {
        printf(
                "The last element has the number %d, but got %d. "
                "Nothing has been deleted.\n\n",
                listLength,
                choice
        );

        return -1;
    }

    return choice;
}

listElement *delListElem(listElement *list) {
    /* YOUR CODE HERE */
    int choice = listElementPicker(list);

    if (choice == -1) return list;

    if (choice == 1) {
        listElement *next = list->nextElem;

        free(list);

        return next;
    }

    listElement *previous = list;

    while (choice > 2) {
        --choice;
        previous = previous->nextElem;
    }

    listElement *newNext = previous->nextElem->nextElem;

    free(previous->nextElem);

    previous->nextElem = newNext;

    /* ---------------*/

    return list;
}

void delList(listElement *list) {
    /* YOUR CODE HERE */
    while (list) {
        listElement *previous = list;
        list = list->nextElem;

        free(previous);
    }
    /* ---------------*/
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
