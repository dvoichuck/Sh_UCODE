//
// Created by Dima Voichuck on 12/5/20.
//

#include "ush.h"

void mx_builtin_manager(t_ush *ush, t_list **new_list, char **envp) {
    t_list *cmd_arr = (*new_list);
//    t_list *cmd_arr_2 = (*new_list);
//
//    while (cmd_arr_2) {
//        printf("list = %s\n", cmd_arr_2->data);
//        cmd_arr_2 = cmd_arr_2->next;
//    }
    while ((*new_list) != NULL) {
        if (mx_strcmp((*new_list)->data, "exit") == 0) {
            mx_exit(ush, new_list);
        }

        else if (mx_strcmp((*new_list)->data, "env") == 0)
            mx_env(ush, (*new_list), envp);
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
    while (cmd_arr) {
        free(cmd_arr->data);
        mx_pop_front(&cmd_arr);
    }
}
