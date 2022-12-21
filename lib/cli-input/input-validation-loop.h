//
// Created by fhs on 21.12.2022.
//

#ifndef C_COURSE_INPUT_VALIDATION_LOOP_H
#define C_COURSE_INPUT_VALIDATION_LOOP_H

typedef int (*Validator)(const char *);

void validatedInput(const char *prompt, const char *errorMsg, Validator validator, char *input);

#endif //C_COURSE_INPUT_VALIDATION_LOOP_H
