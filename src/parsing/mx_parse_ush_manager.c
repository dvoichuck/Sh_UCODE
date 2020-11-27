#include "ush.h"

static void parse_str_input(t_ush *ush, char *envp[]) {
    int first = 0;
    int last = 0;
    int len = mx_strlen(ush->str_input);
    t_list *new_list = NULL;
    ush->triger = 0;
    for (int i = 0; i < len; i++) {
        ush->triger = 0;
        if (ush->str_input[i] != ' ') {
            char *str = NULL;
            first = i;
            while (ush->str_input[i] != ' ' && ush->str_input[i] != '\0') {
                if (ush->str_input[i] == '"')
                    mx_parse_quotes(ush, &first, i, &new_list);
                if (ush->str_input[i] == ';')
                    mx_parse_semicolon(ush, &new_list, &first, i);
                i++;
            }
            if (ush->triger == 0) {
                last = i;
                str = mx_substr(ush->str_input, first, last);
                mx_del_char(&str, mx_strlen(str) - 1, '\n');
                mx_push_back(&new_list, str);
            }
        }
    }
    ush->triger = 0;
    t_list *command_arr = new_list;
    while (command_arr != NULL) {
        if (mx_strcmp(command_arr->data, "exit") == 0 && ush->triger == 0) {
            mx_printstr("exit\n");
            ush->event = false;
            system("leaks -q ush");
            exit(1);
        }
        else if (mx_strcmp(command_arr->data, "env") == 0 && ush->triger == 0)
            mx_env(ush, envp);
        else if (mx_strcmp(command_arr->data, "pwd") == 0 && ush->triger == 0) {
            command_arr = command_arr->next;
            if (command_arr == NULL ||
                mx_strcmp(command_arr->data, ";") == 0) {
                mx_pwd(ush);
            }
            else {
                mx_printstr("pwd: too many arguments\n");
                ush->triger = 1;
            }
        }
//        else if (mx_strcmp(command_arr->data, "which") == 0) {
//            command_arr = command_arr->next;
//            mx_which(ush, command_arr->data);
//        }
        else if (mx_strcmp(command_arr->data, "cd") == 0 && ush->triger == 0) {
            command_arr = command_arr->next;
            if (command_arr == NULL || mx_strcmp(command_arr->data, ";") == 0)
                mx_cd(ush, NULL);
            else
                mx_cd(ush, command_arr->data);
        }
        else
            mx_unix_commands_launcher(ush, command_arr);

        if (command_arr != NULL) {
            if (mx_strcmp(command_arr->data, ";") == 0) {
                ush->triger = 0;
            }
            command_arr = command_arr->next;
        }
    }
    while (new_list) {
        free(new_list->data);
        mx_pop_front(&new_list);
    }
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
    }
    if (malloc_size(ush->str_input)) {
        free(ush->str_input);
        ush->str_input = NULL;
    }
    if (malloc_size(str_del_char))
        free(str_del_char);
}
