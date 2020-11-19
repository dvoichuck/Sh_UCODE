//
// Created by Dima Voichuck on 11/18/20.
//

#include "ush.h"

void mx_parse_ush_manager(t_ush *ush) {
    if (mx_strcmp(ush->str_input, "exit") == 0) {
        mx_printstr("exit\n");
        ush->works = false;
        exit(1);
    }
    else {
        mx_printstr("ush: command not found: ");
        mx_printstr(ush->str_input);
        free(ush->str_input);
        ush->str_input = NULL;
    }
}
