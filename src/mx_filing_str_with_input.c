//
// Created by Dima Voichuck on 11/17/20.
//

#include "ush.h"

void mx_filling_str_with_input(t_ush *ush, char *ch) {
    char *str = NULL;

    str = mx_strjoin(ush->str_input, ch);
    free(ush->str_input);
    ush->str_input = mx_strdup(str);
    free(str);
}
