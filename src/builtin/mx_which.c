//
// Created by Igor Khanenko on 11/23/20.
//

#include "ush.h"

static bool check_exe_file (char *path) {
    struct stat lsb;
    bool exe_file_exist = false;

    lstat(path, &lsb);
    if ((lsb.st_mode & S_IXUSR) == S_IXUSR) {
        exe_file_exist = true;
    }
    return exe_file_exist;
}

static bool check_ush_cmd(char *cmd_name) {
    bool cmd_in_ush_builtin = false;

    if (mx_strcmp(cmd_name, "env") == 0)
        cmd_in_ush_builtin = true;
    else if (mx_strcmp(cmd_name, "cd") == 0)
        cmd_in_ush_builtin = true;
    else if (mx_strcmp(cmd_name, "pwd") == 0)
        cmd_in_ush_builtin = true;
    else if (mx_strcmp(cmd_name, "which") == 0)
        cmd_in_ush_builtin = true;
    else if (mx_strcmp(cmd_name, "echo") == 0)
        cmd_in_ush_builtin = true;

    return cmd_in_ush_builtin;
}

void mx_which(t_ush *ush, t_list *cmd, t_env *env) {
    char **path_env = mx_strsplit(getenv("PATH"), ':');
    char **path = (char **)malloc(sizeof(char *) * 2);
    t_list *node_buf = cmd;

    if (!node_buf->next)
        mx_error_usage_which();
    else {
        node_buf = node_buf->next;
        if (check_ush_cmd(node_buf->data) == true)
            mx_shell_built_in_command(node_buf->data);
        for (int k = 0; k < 2; k++)
            path[k] = NULL;
        for (int i = 0; path_env[i] != NULL; i++) {
            path[0] = mx_strjoin_ush(path_env[i], node_buf->data);
            if (check_exe_file(path[0]) == true) {
                mx_printstr(path[0]);
                mx_printchar('\n');
                break;
            }
            free(path[0]);
            path[0] = NULL;
        }
        mx_del_strarr(&path_env);
        mx_del_strarr(&path);
    }
}
