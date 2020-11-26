//
// Created by Igor Khanenko on 11/23/20.
//

#include "ush.h"

void mx_unix_commands_launcher(t_ush *ush, t_list *cmd) {
    char **path_env = mx_strsplit(getenv("PATH"), ':');
    char *path_buf = NULL;

    for (int i = 0; path_env[i] != NULL; i++) {
        path_buf = mx_strjoin_uls(path_env[i], cmd->data);
    }
    mx_del_strarr(&path_env);
    free(path_buf);
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
