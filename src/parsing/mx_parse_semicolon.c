//
// Created by Dima Voichuck on 11/26/20.
//

#include "ush.h"

void mx_parse_semicolon(t_ush *ush, t_list **new_list, int *first, int i) {
    mx_push_back(&(*new_list),
                 mx_substr(ush->str_input, (*first), i));
    if ((*first) != i) {
        mx_push_back(&(*new_list),
                     mx_substr(ush->str_input, i, i));
        ush->count_list++;
    }
    (*first) = i + 1;
    ush->count_list++;
}
