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

static void flags_and_argv_parsing(t_list *cmd, char ***path) {
    t_list *node_buf = cmd;

    for (int i = 1; node_buf->next; i++) {
        node_buf = node_buf->next;
        (*path)[i] = strdup(node_buf->data);
    }
}

void mx_unix_commands_launcher(t_ush *ush, t_list *cmd, t_env *env) {
    char **path_env = mx_strsplit(getenv("PATH"), ':');
    char **path = (char **)malloc(sizeof(char *) * ush->count_list + 1);

    for (int k = 0; k < ush->count_list + 1; k++)
        path[k] = NULL;
    for (int i = 0; path_env[i] != NULL; i++) {
        path[0] = ush->exe == false ? mx_strjoin_ush(path_env[i], cmd->data)
                                    : cmd->data;
        if (check_exe_file(path[0]) == true) {
            if (cmd->next != NULL)
                flags_and_argv_parsing(cmd, &path);
            mx_child_process(ush, cmd->data, path, env);
            break;
        }
        if (path_env[i + 1] == NULL) {
            mx_error_command_not_found(cmd->data);
            break;
        }
        free(path[0]);
        path[0] = NULL;
    }
    if (malloc_size(path_env))
        mx_del_strarr(&path_env);
    if (malloc_size(path))
        mx_del_strarr(&path);
}
