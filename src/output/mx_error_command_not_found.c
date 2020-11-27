//
// Created by Igor Khanenko on 11/26/20.
//

#include "ush.h"

void mx_error_command_not_found (char *cmd_name) {
    mx_printstr("u$h: command not found: ");
    mx_printstr(cmd_name);
    mx_printchar('\n');
}
