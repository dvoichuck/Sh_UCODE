//
// Created by Igor Khanenko on 12/2/20.
//

#include "ush.h"

void mx_shell_built_in_command(char *cmd_name) {
    mx_printstr(cmd_name);
    mx_printstr(": shell built-in command\n");
}
