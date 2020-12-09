//
// Created by Dima Voichuck on 12/5/20.
//

#include "ush.h"

static void del_list(t_list **new_list) {
    while ((*new_list)) {
        free((*new_list)->data);
        mx_pop_front(&(*new_list));
    }
}

void mx_parse_str_input(t_ush *ush, char **envp) {
    int first = 0;
    int len = mx_strlen(ush->str_input);
    t_list *new_list = NULL;

    ush->triger = 0;
    for (int i = 0; i < len; i++) {
        ush->triger = 0;
        if (ush->str_input[i] != ' ') {
            char *str = NULL;
            first = i;
            while (ush->str_input[i] != ' ' && ush->str_input[i] != '\0'
            && ush->str_input[i] != '\n') {
                ush->triger = 0;
                if (ush->str_input[i] == '"')
                    mx_parse_quotes(ush, &first, &i, &new_list);
                if (ush->str_input[i] == ';') {
                    if (ush->str_input[i + 1] == ';') {
                        i = len - 1;
                        ush->triger = 1;
                        del_list(&new_list);
                        mx_printerr("u$h: parse error near ';;'\n");
                    }
                    else {
                        mx_parse_semicolon(ush, &new_list, &first, i);
                        mx_builtin_manager(ush, &new_list, envp);
                    }
                }
                i++;
            }
            if (ush->triger == 0 && first != i) {
                str = mx_substr(ush->str_input, first, i);
                mx_push_back(&new_list, str);
                ush->count_list++;
            }
        }
    }
    mx_builtin_manager(ush, &new_list, envp);
    del_list(&new_list);
}
