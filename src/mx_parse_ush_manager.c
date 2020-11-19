//
// Created by Dima Voichuck on 11/18/20.
//

#include "ush.h"

static void parse_str_input(t_ush *ush) {
    int i = mx_count_words(ush->str_input, ' ');
//    mx_create_node()
}

void mx_parse_ush_manager(t_ush *ush) {
    char *str_del_char = mx_del_extra_spaces(ush->str_input);

    if (str_del_char[0] == '\0')
        mx_printstr("");
    else {
        parse_str_input(ush);
        if (ush->str_input[0] == '\n')
            mx_printstr("");
        else if (mx_strcmp(ush->str_input, "exit\n") == 0) {
            mx_printstr("exit\n");
            exit(1);
        }
        else {
            mx_printerr("ush: command not found: ");
            mx_printerr(ush->str_input);
        }
    }
    free(ush->str_input);
    ush->str_input = NULL;
}
