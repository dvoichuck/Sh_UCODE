//
// Created by Dima Voichuck on 12/5/20.
//

#include "ush.h"

void mx_output_manager(t_ush *ush, t_list *new_list, char **envp) {
    ush->triger = 0;
    t_list *cmd_arr = new_list;
    while (cmd_arr != NULL) {
        if (mx_strcmp(cmd_arr->data, "exit") == 0 && ush->triger == 0) {
            mx_printstr("exit\n");
            ush->event = false;
            system("leaks -q ush");
            exit(errno);
        }
        else if (mx_strcmp(cmd_arr->data, "env") == 0 && ush->triger == 0)
            mx_env(ush, envp);
        else if (mx_strcmp(cmd_arr->data, "pwd") == 0 && ush->triger == 0) {
            cmd_arr = cmd_arr->next;
            if (cmd_arr == NULL ||
                mx_strcmp(cmd_arr->data, ";") == 0) {
                mx_pwd(ush);
            }
            else {
                mx_printstr("pwd: too many arguments\n");
                ush->triger = 1;
            }
        }
//        else if (mx_strcmp(cmd_arr->data, "which") == 0) {
//            cmd_arr = cmd_arr->next;
//            mx_which(ush, cmd_arr->data);
//        }
        else if (mx_strcmp(cmd_arr->data, "cd") == 0 && ush->triger == 0) {
            cmd_arr = cmd_arr->next;
            if (cmd_arr == NULL || mx_strcmp(cmd_arr->data, ";") == 0)
                mx_cd(ush, NULL);
            else
                mx_cd(ush, cmd_arr->data);
        }
        else if (mx_strcmp(cmd_arr->data, "which") == 0 && ush->triger == 0)
            mx_which(ush, cmd_arr, envp);
        else if (mx_strcmp(cmd_arr->data, "echo") == 0 && ush->triger == 0)
            mx_echo(ush, cmd_arr);
        else
            if ((cmd_arr) && mx_strcmp(cmd_arr->data, ";") != 0) {
                char *str = cmd_arr->data;
                if (str[0] == '/')
                    ush->exe = true;
                else
                    ush->exe = false;
                mx_unix_commands_launcher(ush, cmd_arr, envp);
            }
        while (cmd_arr != NULL) {
            if (mx_strcmp(cmd_arr->data, ";") == 0) {
                ush->triger = 0;
                cmd_arr = cmd_arr->next;
                break;
            }
            cmd_arr = cmd_arr->next;
        }
    }
//    while (new_list) {
//        free(new_list->data);
//        mx_pop_front(&new_list);
//    }
}
