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

static char *flags_and_path_creator(t_list *cmd, char *path) {
    char *path_buf = NULL;
    char *space_open_quotes = (char *)malloc(sizeof(char) * 2);
    char *closing_quotes = (char *)malloc(sizeof(char) * 1);
    t_list *buf_cmd = cmd;

    space_open_quotes[0] = 32;
    space_open_quotes[1] = 34;
    closing_quotes[0] = 34;
    path_buf = mx_strjoin(path, space_open_quotes);
    while (buf_cmd->next) {
        buf_cmd = buf_cmd->next;
        path_buf = mx_strjoin(path_buf, buf_cmd->data);
    }
    path_buf = mx_strjoin(path_buf, closing_quotes);

    return path_buf;
}

void mx_unix_commands_launcher(t_ush *ush, t_list *cmd, char **envp) {
    char **path_env = mx_strsplit(getenv("PATH"), ':');
    char **path_buf = (char **)malloc(sizeof(char *) * 2);


    for (int k = 0; k < 2; k++)
        path_buf[k] = NULL;
    for (int i = 0; path_env[i] != NULL; i++) {
        path_buf[0] = mx_strjoin_ush(path_env[i], cmd->data);
//        printf("Path_buf[%d] = %s\n", i, path_buf[0]);
        if (check_exe_file(path_buf[0]) == true) {
            if (cmd->next != NULL)
                path_buf[0] = flags_and_path_creator(cmd, path_buf[0]);
//            while (buf_cmd->next) {
//                buf_cmd = buf_cmd->next;
//                path_buf[0] = mx_strjoin(path_buf[0], 3234);
//                path_buf[0] = mx_strjoin(path_buf[0], buf_cmd->data);
//            }
            mx_child_process(ush, path_buf, envp);
            break;
        }
        if (path_env[i + 1] == NULL)
            mx_error_command_not_found(cmd->data);
        free(path_buf[0]);
        path_buf[0] = NULL;
    }
    mx_del_strarr(&path_env);
    mx_del_strarr(&path_buf);
}

//void mx_unix_commands_launcher(t_ush *ush, t_list *cmd) {
//    int status;
//    char *args[2];
//
//    if (cmd)
//        args[0] = mx_strjoin("/bin/", cmd->data);        // first arg is the full path to the executable
//    args[1] = NULL;             // list of args must be NULL terminated
//
//    if ( fork() == 0 )
//        execv( args[0], args ); // child: call execv with the path and the args
//    else
//        wait( &status );        // parent: wait for the child (not really necessary)
//}
