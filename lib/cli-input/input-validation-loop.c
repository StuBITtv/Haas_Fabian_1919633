//
// Created by fhs on 21.12.2022.
//

#include <stdio.h>
#include "input-validation-loop.h"

void validatedInput(const char *prompt, const char *errorMsg, Validator validator, char *input) {
    while (1) {
        printf("%s\n", prompt);
        scanf("%s", input);

        if (validator(input)) return;

        printf("\n%s, instead got \"%s\".\n\n", errorMsg, input);
    }
}
