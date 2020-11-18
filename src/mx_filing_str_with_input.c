//
// Created by Dima Voichuck on 11/17/20.
//

#include "ush.h"

void mx_filling_str_with_input(t_ush *ush, char ch) {
    char *str = NULL;
    char *tmp = mx_strnew(1);
    tmp[0] = ch;

    str = mx_strjoin(ush->str_input, tmp);
    free(tmp);
    free(ush->str_input);
    ush->str_input = NULL;
    ush->str_input = mx_strdup(str);
    free(str);
}
