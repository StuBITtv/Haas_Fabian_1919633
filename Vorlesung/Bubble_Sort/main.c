//
// Created by fhs on 10.01.2023.
//

#include <malloc.h>
#include "list-loader.h"
#include "bubble-sort.h"

int main(void) {
    size_t count;
    FILE *input = fopen("rand.txt", "r");

    double *list = loadList(input, &count);

    fclose(input);

    bubbleSort(list, count);

    for (size_t i = 0; i < count; ++i) {
        printf("%le\n", list[i]);
    }

    free(list);
}
