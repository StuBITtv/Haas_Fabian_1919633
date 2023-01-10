//
// Created by fhs on 10.01.2023.
//

#include <malloc.h>
#include "list-loader.h"

size_t countLines(FILE *file) {
    if (file == NULL) return 0;

    size_t lines = 0;

    int notEmpty = 0;

    while (1) {
        long ch = fgetc(file);

        if (feof(file)) {
            break;
        }

        if (ch == '\n' && notEmpty) {
            notEmpty = 0;
            ++lines;
        } else if (ch != ' ') {
            notEmpty = 1;
        }
    }

    return lines;
}

double *loadList(FILE *file, size_t *lines) {
    *lines = countLines(file);

    rewind(file);

    double *values = malloc(sizeof(double) * *lines);

    for (size_t i = 0; i < *lines; ++i) {
        fscanf(file, "%le", &(values[i]));  // NOLINT(cert-err34-c)
    }

    return values;
}
