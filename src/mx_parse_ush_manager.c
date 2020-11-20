//
// Created by Dima Voichuck on 11/18/20.
//

#include "ush.h"

static void parse_str_input(t_ush *ush) {
    int first;
    int last;
    char **str = (char **)malloc(sizeof(char *) * 2);
    int j = 0;
    for (int i = 0; i < 2; i++)
        str[i] = NULL;
    for (int i = 0; ush->str_input[i] != '\0'; i++) {
        if (mx_isalpha(ush->str_input[i])) {
            first = i;
            for (; mx_isalpha(ush->str_input[i]); i++);
            last = i;
            str[j] = mx_substr(ush->str_input, first, last);
            j++;
        }
        if (ush->str_input[i] == ';') {
            
        }
    }
    printf("first = %d, last = %d, str[0] = %s, str[1] = %s\n", first, last, str[0], str[1]);
    for (int i = 0; str[i]; i++) {
        if (mx_strcmp(str[i], "cd") == 0) {
            cd(str[1])
        }
    }
}

void mx_parse_ush_manager(t_ush *ush, t_list **input) {
    char *str_del_char = mx_del_extra_spaces(ush->str_input);
    if (str_del_char[0] == '\0') {
        mx_printstr("");
    }
    else {
        mx_push_back(input, ush->str_input);
        parse_str_input(ush);
        t_list **all_input = input;
        if (ush->str_input[0] == '\n')
            mx_printstr("");
        else if (mx_strcmp(ush->str_input, "exit\n") == 0) {
            mx_printstr("exit\n");
            for (int i = 0; i < 3; i++) {
                printf("%s", (*all_input)->data);
                (*all_input) = (*all_input)->next;
            }
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
