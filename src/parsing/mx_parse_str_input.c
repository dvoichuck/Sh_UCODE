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
        if (ush->str_input[i] != ' ') {
            char *str = NULL;
            first = i;
            while (ush->str_input[i] != ' ' && ush->str_input[i] != '\0'
            && ush->str_input[i] != '\n') {
                if (ush->str_input[i] == '"')
                    mx_parse_quotes(ush, &first, &i, &new_list);
                if (ush->str_input[i] == ';')
                    mx_parse_semicolon(ush, &new_list, &first, i);
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
    mx_output_manager(ush, new_list, envp);
}
