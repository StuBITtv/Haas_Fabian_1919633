//
// Created by fhs on 10.01.2023.
//

#include "bubble-sort.h"

void bubbleSort(double *list, size_t size) {
    int sorted = 0;

    while (!sorted) {
        sorted = 1;

        for (size_t i = 0; i < size - 1; ++i) {
            if (list[i] > list[i + 1]) {
                sorted = 0;

                double temp = list[i + 1];
                list[i + 1] = list[i];
                list[i] = temp;
            }
        }

        --size;
    }
}
