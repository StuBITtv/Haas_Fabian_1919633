#include <stdio.h>
#include <stdlib.h>
#include "linkedListLib.h"
#include "os-detection.h"

#if defined(IS_WINDOWS)
#define clear() system("cls")
#elif defined(IS_UNIX) || defined(IS_OSX)
#define clear() system("clear")
#endif

/*******************************************************
* NAME: main.c (main) 
*
* AUTHOR: jannik wiessler
*
* DATE: 2020-05-21
*
* DESCRIPTION:  Implementation of a simple linked list programm.
*               UI-menu containing the following options:
*                   >> print list
*                   >> add element
*                   >> delete specific element
*                   >> delete whole list
*                   >> save current list to *.txt file
*                   >> load a stored list from *.txt file
*                   >> sort current list by user defined cirteria
*                   >> dlg for saving current list by exiting the program
*
* DEPENDENCIES: 
*   >> HA03_listL.c
*   >> myFunction.h
*
* INFO: For DHBW use only.
*   >> Typdef of struct
*   >> Practice of simple linked list
*
**/

listElement *cli(listElement *list) {
    while (1) {
        printf("1... print list\n");
        printf("2... add element\n");
        printf("3... delete element\n");
        printf("4... delete list\n");
        printf("5... save list\n");
        printf("6... load list\n");
        printf("7... sort list\n");
        printf("0... quit\n");

        int FLAG = numberInput(1);

        clear();

        switch (FLAG) {
            case 1:
                printList(list);
                break;
            case 2:
                list = addListElem(list);
                break;
            case 3:
                list = delListElem(list);
                break;
            case 4:
                delList(list);
                list = NULL;
                break;
            case 5:
                saveList(list);
                break;
            case 6:
                list = loadList(list);
                break;
            case 7:
                list = sortList(list);
                break;
            case 0:
                return list;
            default:
                printf("invalid choice\n");
                break;
        }
    }
}

int main() {
    listElement *list = cli(NULL);

    exitFcn(list);

    delList(list);
}
