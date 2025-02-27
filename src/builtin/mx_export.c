//
// Created by Igor Khanenko on 12/7/20.
//

#include "ush.h"

static void name_and_value_parse(t_list *cmd, char **name, char **value) {
    char **buf_arr = mx_strsplit(cmd->data, '=');

    (*name) = strdup(buf_arr[0]);
    (*value) = strdup(buf_arr[1]);

    if (malloc_size(buf_arr))
        mx_del_strarr(&buf_arr);
}

void mx_export(t_ush *ush, t_list *cmd, t_env **env) {
    char *name = NULL;
    char *value = NULL;
    int status = 0;
    int exist_in_env = 0;

    if (cmd->next != NULL) {
        cmd = cmd->next;
        name_and_value_parse(cmd, &name, &value);
        exist_in_env = (getenv(name) != 0) ? 1 : 0;
        status = setenv(name, value, exist_in_env);
        if (status == 0)
            mx_refilling_env(env, cmd->data);
        else
            errno = 1;
    }
    else {
        t_list *exp_buf = (*env)->export;

        while (exp_buf != NULL) {
            mx_printstr(exp_buf->data);
            mx_printchar('\n');
            exp_buf = exp_buf->next;
        }
    }
    if (malloc_size(name))
        free(name);
    if (malloc_size(value))
        free(value);
}
