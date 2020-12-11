//
// Created by Dima Voichuck on 12/5/20.
//

#include "ush.h"

void mx_builtin_manager(t_ush *ush, t_list **new_list, t_env *env) {
    t_list *cmd_arr = (*new_list);
//    t_list *cmd_arr_2 = (*new_list);
////
//    while (cmd_arr_2) {
//        printf("list = %s\n", cmd_arr_2->data);
//        cmd_arr_2 = cmd_arr_2->next;
//    }
    while ((*new_list) != NULL) {
        if (mx_strcmp((*new_list)->data, "exit") == 0) {
            mx_exit(ush, env, new_list);
        }
//        else if (input->ch[0] == '\x04' && input->index == 0) {
//            dprintf(1, "exit\n");
//            exit(0);
//        }
        else if (mx_strcmp((*new_list)->data, "export") == 0)
            mx_export(ush, (*new_list), &env);
        else if (mx_strcmp((*new_list)->data, "env") == 0)
            mx_env(ush, (*new_list), &env);
        else if (mx_strcmp((*new_list)->data, "pwd") == 0) {
            (*new_list) = (*new_list)->next;
            if ((*new_list) == NULL) {
                mx_pwd(ush);
            }
            else
                if ((*new_list))
                    mx_printstr("pwd: too many arguments\n");
        }
        else if (mx_strcmp((*new_list)->data, "cd") == 0) {
            (*new_list) = (*new_list)->next;
            if ((*new_list) == NULL)
                mx_cd(ush, NULL);
            else
                mx_cd(ush, (*new_list)->data);
        }
        else if (mx_strcmp((*new_list)->data, "which") == 0)
            mx_which(ush, (*new_list), env);
        else if (mx_strcmp((*new_list)->data, "echo") == 0)
            mx_echo(ush, (*new_list));
        else if ((*new_list)) {
            char *str = (*new_list)->data;
            if (str[0] == '/')
                ush->exe = true;
            else
                ush->exe = false;
            mx_unix_commands_launcher(ush, (*new_list), env);
        }
        while ((*new_list) != NULL) {
            (*new_list) = (*new_list)->next;
        }
    }
    while (cmd_arr) {
        if (malloc_size(cmd_arr->data)) {
            free(cmd_arr->data);
        }
        if (malloc_size(cmd_arr))
            mx_pop_front(&cmd_arr);
    }
}
