#include <stdio.h>
#include <string.h>
#include "linkedListLib.h"
#include "os-detection.h"

#if defined(IS_WINDOWS)
#define printDirectory() system("dir *.txt")
#elif defined(IS_UNIX) || defined(IS_OSX)
#define printDirectory() system("ls *.txt")
#endif


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

static listElement *getLastElement(listElement *list) {
    if (!list) return NULL;

    while (list->nextElem) {
        list = list->nextElem;
    }

    return list;
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

    getLastElement(list)->nextElem = new;

    return list;
}

static void writeListToFile(FILE *file, const listElement *list) {
    int index = 0;
    while (list) {
        fprintf(file, "%d.", ++index);
        fprintf(file, "\t last name: %s\n", list->lastName);
        fprintf(file, "\t first name: %s\n", list->firstName);
        fprintf(file, "\t age: %d\n", list->age);

        list = list->nextElem;
    }

    printf("\n");
}

static int emptyListExit(const listElement *list) {
    if (!list) {
        printf("The list is empty. Nothing left to do.\n\n");
        return -1;
    }

    return 0;
}

void printList(const listElement *list) {
    if (emptyListExit(list)) return;

    printf("current list:\n\n");

    writeListToFile(stdout, list);
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
    if (emptyListExit(list)) return -1;

    printList(list);
    printf("Which element from the above do you want to delete?\n");

    int listLength = getLenOfList(list);
    int choice = numberInput(getMaximalDigits(listLength) + 40);

    if (choice < 1 || choice > listLength) {
        printf(
                "Element numbers range from 1 to %d, but got %d. "
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

static void fileNameInput(char *fileName) {
    printf("What's the name of the save file?\n");
    scanf("%s", fileName);
}

void saveList(const listElement *list) {
    /* YOUR CODE HERE */
    if (emptyListExit(list)) return;

    char fileName[512];
    fileNameInput(fileName);

    FILE *saveFile = fopen(fileName, "w");

    if (!saveFile) {
        printf("Could write to file %s. Check you permissions.\n\n", fileName);
        return;
    }

    printf("Writing to file %s... ", fileName);

    writeListToFile(saveFile, list);

    fclose(saveFile);
    printf("Done.\n\n");
    /* ---------------*/
}

static void readLine(FILE *file, char **buffer, int *bufferSize) {
    if (!(*buffer)) {
        *bufferSize = 100;
        *buffer = malloc(*bufferSize);
    }

    while (1) {
        fgets(*buffer, *bufferSize, file);

        char lastChar = (*buffer)[strlen(*buffer) - 1];

        if (lastChar == '\n' || feof(file)) {
            break;
        }

        fseek(file, ((*bufferSize) - 1) * -1, SEEK_CUR);

        *bufferSize = (*bufferSize) * 2 + 1;
        *buffer = realloc(*buffer, *bufferSize);
    }
}

static void parseLine(FILE *saveFile, char **buffer, int *bufferSize) {
    while (!(*buffer) || !feof(saveFile) && !strchr(*buffer, ':')) {
        readLine(saveFile, buffer, bufferSize);
    }

    if (feof(saveFile)) return;

    // trim data
    (*buffer)[strlen(*buffer) - 1] = '\0';

    char *dataStart = strchr(*buffer, ':') + 1;
    for (; *dataStart == ' ' && *dataStart != '\0'; ++dataStart);

    strcpy(*buffer, dataStart);


    char *dataEnd = strchr(*buffer, ' ');
    if (dataEnd) *dataEnd = '\0';
}

static void copyLineBuffer(char *destination, const char *buffer) {
    strncpy(destination, buffer, 49);
    destination[49] = '\0';
}

static listElement *parseList(FILE *saveFile) {
    listElement *list = NULL;

    char *lineBuffer = NULL;
    int lineBufferSize = 0;

    listElement *previous = NULL;

    while (1) {
        parseLine(saveFile, &lineBuffer, &lineBufferSize);

        if (feof(saveFile)) {
            break;
        }

        listElement *new = malloc(sizeof(listElement));
        new->nextElem = NULL;

        copyLineBuffer(new->lastName, lineBuffer);

        parseLine(saveFile, &lineBuffer, &lineBufferSize);
        copyLineBuffer(new->firstName, lineBuffer);

        parseLine(saveFile, &lineBuffer, &lineBufferSize);
        new->age = atoi(lineBuffer);    // NOLINT(cert-err34-c)

        if (!previous) {
            list = new;
            previous = new;
        } else {
            previous->nextElem = new;
            previous = new;
        }
    }

    return list;
}

listElement *loadList(listElement *list) {
    /* YOUR CODE HERE */
    printDirectory();
    printf("\n");

    char fileName[512];
    fileNameInput(fileName);

    FILE *saveFile = fopen(fileName, "r");

    if (!saveFile) {
        printf("Could not open %s\n\n", fileName);
        return NULL;
    }

    listElement *listEnd = getLastElement(list);

    if(listEnd) {
        list->nextElem = parseList(saveFile);
    } else {
        list = parseList(saveFile);
    }

    printf("Appending save file to current list...\n");

    fclose(saveFile);

    printf("Done.\n\nPrinting the new list...\n");
    printList(list); // show loaded list
    /* ---------------*/

    return list;
}

void exitFcn(listElement *list) {
    if (list) {
        printf("Do you want to safe the list?\n1... Yes\n2... No\n");

        while (1) {
            int choice = numberInput(1);

            if (choice == 1) {
                saveList(list);
                return;
            } else if (choice == 2) {
                return;
            }

            printf("\nWrite 1 to save the list or 2 to discard the changes\n");
        }
    }
}

listElement *sortList(listElement *list) {
    printf("\n>>sortList fcn is tbd.\n\n");

    return list;
}

void stringToLower(char *string) {
    printf("\n>>stringToLower fcn is tbd.\n\n");
}
