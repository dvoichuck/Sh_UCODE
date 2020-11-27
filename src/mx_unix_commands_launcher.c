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

void mx_unix_commands_launcher(t_ush *ush, t_list *cmd) {
    char **path_env = mx_strsplit(getenv("PATH"), ':');
    char **path_buf = (char **)malloc(sizeof(char *) * 2);

    for (int k = 0; k < 2; k++)
        path_buf[k] = NULL;
    for (int i = 0; path_env[i] != NULL; i++) {
        path_buf[0] = mx_strjoin_ush(path_env[i], cmd->data);
//        printf("Path_buf[%d] = %s\n", i, path_buf[0]);
        if (check_exe_file(path_buf[0]) == true) {
            execv(path_buf[0], path_buf);
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
