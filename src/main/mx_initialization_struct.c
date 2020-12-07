//
// Created by Dima Voichuck on 11/17/20.
//
#include "ush.h"

void mx_initialization_struct(t_ush *ush) {
    ush->home = NULL;
    ush->user = NULL;
    ush->str_input = NULL;
    ush->dir_path = NULL;
    ush->event = true;
    ush->triger = 0;
    ush->count_list = 0;
}
