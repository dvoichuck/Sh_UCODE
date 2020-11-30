#pragma once

#include "libmx.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <dirent.h> // for opendir, readdir, closedir
#include <pwd.h>
#include <grp.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <sys/ioctl.h>
#include <time.h>
#include <stdlib.h>
#include <termios.h>
#include <stdio.h>
#include <fcntl.h>

#define MAX_LEN 1024

typedef struct s_ush {
    char *str_input;
    char *dir_path;
    char *which_path;
    int triger;
    bool event;
} t_ush;

/*
 * MAIN
 */
void mx_initialization_struct(t_ush *ush);


/*
 * PARSE
 */
void mx_parse_ush_manager(t_list **input, t_ush *ush, char **envp);
void mx_parse_semicolon(t_ush *ush, t_list **new_list, int *first, int i);
void mx_parse_quotes(t_ush *ush, int *first, int i, t_list **new_list);
void mx_signals();

/*
 * INPUT FUNCTION
 */
void mx_input(char **envp);
void mx_filling_str_with_input(t_ush *ush, char ch);


/*
     * BUILTIN'S COMMANDS
 */
void mx_env(t_ush *ush, char **envp);
void mx_cd(t_ush *ush, char *path);
void mx_pwd (t_ush *ush);
void mx_which(t_ush *ush, char *cmd);

/*
 * UNIX COMMANDS
 */
void mx_unix_commands_launcher(t_ush *ush, t_list *cmd, char **envp);
void mx_child_process(t_ush *ush, char **path, char **envp);

/*
 * OUTPUT
 */
void mx_error_command_not_found (char *cmd_name);
