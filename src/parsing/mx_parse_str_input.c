//
// Created by Dima Voichuck on 12/5/20.
//

#include "ush.h"

void mx_parse_str_input(t_ush *ush, char **envp) {
    int first = 0;
    int len = mx_strlen(ush->str_input);
    t_list *new_list = NULL;
    ush->triger = 0;
    for (int i = 0; i < len; i++) {
        ush->triger = 0;
        ush->count_list = 0;
        if (ush->str_input[i] != ' ') {
            char *str = NULL;
            first = i;
            while (ush->str_input[i] != ' ' && ush->str_input[i] != '\0'
            && ush->str_input[i] != '\n') {
                if (ush->str_input[i] == '"')
                    mx_parse_quotes(ush, &first, &i, &new_list);
                if (ush->str_input[i] == ';') {
                    if (i != first) {
                        str = mx_substr(ush->str_input, first, i);
                        mx_push_back(&new_list, str);
                    }
//                    mx_parse_semicolon(ush, &new_list, &first, i);
                    if (new_list->data) {
                        mx_output_manager(ush, new_list, envp);
                    }
                    ush->triger = 1;
                }
                i++;
            }
            if (ush->triger == 0 && first != i) {
                str = mx_substr(ush->str_input, first, i);
//                mx_del_char(&str, mx_strlen(str) - 1, '\n');
                mx_push_back(&new_list, str);
                ush->count_list++;
            }
        }
    }
    if (new_list && ush->triger == 0) {
        char *str = new_list->data;
        mx_output_manager(ush, new_list, envp);
    }
}
