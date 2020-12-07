//
// Created by Igor Khanenko on 12/7/20.
//

#include "ush.h"

static void name_and_value_parse(t_list *cmd, char **name, char **value) {
    char **buf_arr = mx_strsplit(cmd->data, '=');
//    char **buf_value = NULL

    (*name) = strdup(buf_arr[0]);
    (*value) = strdup(buf_arr[1]);
}

void mx_export(t_ush *ush, t_list *cmd, char **envp) {
    char *name = NULL;
    char *value = NULL;
    int status = 0;
    int exist_in_env = 0;

    if (cmd->next != NULL) {
        cmd = cmd->next;
        name_and_value_parse(cmd, &name, &value);
        exist_in_env = (getenv(name) != 0) ? 0 : 1;
        status = setenv(name, value, exist_in_env);
        errno = status == 0 ? 0 : -1;
    }
    else {
        mx_printstr("Тут должен быть список имен всех переменных, отмеченных для экспорта в дочерние процессы!\n");
    }
}
