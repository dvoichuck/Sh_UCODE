//
// Created by Dima Voichuck on 12/5/20.
//

#include "ush.h"

void mx_output_manager(t_ush *ush, t_list **new_list, char **envp) {
    ush->triger = 0;
//    t_list *cmd_arr = (*new_list);

    while ((*new_list) != NULL) {
        if (mx_strcmp((*new_list)->data, "exit") == 0) {
            mx_printstr("exit\n");
            system("leaks -q ush");
            (*new_list) = (*new_list)->next;
            ush->event = false;
            exit(errno);
        }
        else if (mx_strcmp((*new_list)->data, "env") == 0)
            mx_env(ush, envp);
        else if (mx_strcmp((*new_list)->data, "pwd") == 0) {
            (*new_list) = (*new_list)->next;
            if ((*new_list) == NULL) {
                mx_pwd(ush);
            }
            else
                if ((*new_list))
                    mx_printstr("pwd: too many arguments\n");
        }
//        else if (mx_strcmp(cmd_arr->data, "which") == 0) {
//            cmd_arr = cmd_arr->next;
//            mx_which(ush, cmd_arr->data);
//        }
        else if (mx_strcmp((*new_list)->data, "cd") == 0) {
            (*new_list) = (*new_list)->next;
            if ((*new_list) == NULL)
                mx_cd(ush, NULL);
            else
                mx_cd(ush, (*new_list)->data);
        }
        else if (mx_strcmp((*new_list)->data, "which") == 0)
            mx_which(ush, (*new_list), envp);
        else if (mx_strcmp((*new_list)->data, "echo") == 0)
            mx_echo(ush, (*new_list));
        else if ((*new_list)) {
            char *str = (*new_list)->data;
            if (str[0] == '/')
                ush->exe = true;
            else
                ush->exe = false;
            mx_unix_commands_launcher(ush, (*new_list), envp);
        }
        while ((*new_list) != NULL) {
            (*new_list) = (*new_list)->next;
        }
    }
//    while ((*new_list)) {
//        free((*new_list)->data);
//        mx_pop_front(&(*new_list));
//    }
}
