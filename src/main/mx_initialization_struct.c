//
// Created by Dima Voichuck on 11/17/20.
//
#include "ush.h"

void mx_initialization_struct(t_ush *ush) {
    ush->triger = 0;
    ush->count_list = 0;
    ush->str_input = NULL;
    ush->dir_path = NULL;
    ush->event = true;
}
