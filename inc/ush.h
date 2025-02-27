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
    char *home;
    char *user;
    char *str_input;
    char *dir_path;
    char *which_path;
    int count_list;
    char ch;
    bool triger;
    bool event;
    bool exe; // переменная для игоря который не сказал ее название
}              t_ush;

typedef struct s_environment {
    t_list *env;
    t_list *export;
    char *pwd;
    char *old_pwd;
    char *shlvl;
    int export_size;
}              t_env;

/*
 * MAIN
 */
void mx_initialization_struct(t_ush *ush);
void mx_env_nodes_filling(t_env **env, char **envp);
void mx_non_canon_mode(void);
void mx_free_memory(t_ush **ush, t_env **env, t_list **cmd);

/*
 * PARSE
 */
void mx_parse_str_input(t_ush *ush, t_env *env);
void mx_parse_ush_manager(t_list **input, t_ush *ush, t_env *env);
void mx_parse_semicolon(t_ush *ush, t_list **new_list, int *first, int i);
void mx_parse_quotes(t_ush *ush, int *first, int *i, t_list **new_list);
void mx_signals();

/*
 * INPUT FUNCTION
 */
void mx_input(t_env *env);
void mx_filling_str_with_input(t_ush *ush, char ch);

/*
 * BUILTIN'S COMMANDS
 */
void mx_builtin_manager(t_ush *ush, t_list **new_list, t_env *env);
void mx_exit(t_ush *ush, t_env *env, t_list **new_list);
void mx_export(t_ush *ush, t_list *cmd, t_env **env);
void mx_env(t_ush *ush, t_list *cmd, t_env **env);
void mx_cd(t_ush *ush, char *path);
void mx_pwd (t_ush *ush);
void mx_which(t_ush *ush, t_list *cmd, t_env *env);
void mx_echo(t_ush *ush, t_list *cmd);
void mx_refilling_env(t_env **env, char *env_var);

/*
 * UNIX COMMANDS
 */
void mx_unix_commands_launcher(t_ush *ush, t_list *cmd, t_env *env);
void mx_child_process(t_ush *ush, char *cmd, char **path, t_env *env);

/*
 * ERRORS
 */
void mx_error_command_not_found (char *cmd_name);
void mx_error_usage_which();

/*
 * OUTPUT
 */
void mx_shell_built_in_command(char *cmd_name);
