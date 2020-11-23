//
// Created by Dima Voichuck on 11/18/20.
//

#include "ush.h"


static void parse_str_input(t_ush *ush, char *envp[]) {
    int first = 0;
    int last = 0;
    t_list *command_arr = NULL;

    for (int i = 0; ush->str_input[i] != '\0'; i++) {
        if (ush->str_input[i] != ' ') {
            char *str = NULL;
            first = i;
            while (ush->str_input[i] != ' ' && ush->str_input[i] != '\0')
                i++;
            last = i;
            str = mx_substr(ush->str_input, first, last);
            if (str[mx_strlen(str) - 1] == '\n')
                str[mx_strlen(str) - 1] = '\0';
            mx_push_back(&command_arr, str);
        }
        if (ush->str_input[i] == ';') {
            char *str= mx_substr(ush->str_input, i, i);
            mx_push_back(&command_arr, str);
        }
    }
    while (command_arr != NULL) {
        if (mx_strcmp(command_arr->data, "exit") == 0)
            exit(1);
        else if (mx_strcmp(command_arr->data, "pwd") == 0)
            mx_pwd(ush);
        else if (mx_strcmp(command_arr->data, "cd") == 0) {
            if (command_arr != NULL)
                command_arr = command_arr->next;
            printf("1\n");
            if (command_arr == NULL) {
                mx_cd(ush, NULL);
            }
            else {
                mx_cd(ush, command_arr->data);
            }
        }
        if (command_arr != NULL)
            command_arr = command_arr->next;
    }
    if (malloc_size(command_arr))
        free(command_arr);
//        else if(mx_strcmp(str[0], "env\n") == 0) {
//            mx_env(ush, envp);
//        }
//    }
}

void mx_parse_ush_manager(t_list **input, t_ush *ush, char *envp[]) {
    char *str_del_char = mx_del_extra_spaces(ush->str_input);
    if (str_del_char[0] == '\0') {
        mx_printstr("");
    }
    else {
        mx_push_back(input, ush->str_input);
        parse_str_input(ush, envp);
        t_list **all_input = input;
        if (ush->str_input[0] == '\n')
            mx_printstr("");
//        else if(mx_strcmp(ush->str_input, "pwd\n") == 0) {
//            mx_pwd(ush);
//        }
//        else if(mx_strcmp(ush->str_input, "cd\n") == 0) {
//            mx_cd(ush);
//        }
//        else if(mx_strcmp(ush->str_input, "env\n") == 0) {
//            mx_env(ush, envp);
//        }
//        else if (mx_strcmp(ush->str_input, "exit\n") == 0) {
//            mx_printstr("exit\n");
//            exit(1);
//        }
//        else {
//            mx_printerr("ush: command not found: ");
//            mx_printerr(ush->str_input);
//        }
    }
    free(ush->str_input);
    ush->str_input = NULL;
}


