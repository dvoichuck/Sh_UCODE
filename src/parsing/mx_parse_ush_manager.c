#include "ush.h"

void mx_parse_ush_manager(t_list **input, t_ush *ush, char **envp) {
    char *str_del_char = mx_del_extra_spaces(ush->str_input);
    ush->count_list = 0;

    if (str_del_char[0] == '\0') {
        mx_printstr("");
    }
    else {
        mx_push_back(input, ush->str_input);
        mx_parse_str_input(ush, envp);
//        t_list **all_input = input;
        if (ush->str_input[0] == '\n')
            mx_printstr("");
    }
    if (malloc_size(ush->str_input)) {
        free(ush->str_input);
        ush->str_input = NULL;
    }
    if (malloc_size(str_del_char))
        free(str_del_char);
}
