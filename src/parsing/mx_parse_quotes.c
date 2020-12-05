//
// Created by Dima Voichuck on 11/27/20.
//

#include "ush.h"

void mx_parse_quotes(t_ush *ush, int *first, int *i, t_list **new_list) {
    char *str;
    int last = 0;

    (*first) = (*i) + 1;
    for (; ush->str_input[(*i)] != '\0'; (*i)++)
        if (ush->str_input[(*i)] == '"')
            last = (*i);
    str = mx_substr(ush->str_input, (*first), last);
    mx_push_back(&(*new_list), str);
    ush->triger = 1;
    ush->count_list++;
}
