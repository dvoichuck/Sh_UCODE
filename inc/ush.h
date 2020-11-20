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

typedef struct s_ush {
    char *str_input;
    bool works;
} t_ush;

//
//MAIN
//
void mx_initialization_struct(t_ush *ush);


//
//PARSE
//
void mx_parse_ush_manager(t_ush *ush, t_list **input);

//
// INPUT FUNCTION
//
void mx_input(void);
void mx_filling_str_with_input(t_ush *ush, char ch);
