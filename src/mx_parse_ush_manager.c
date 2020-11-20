//
// Created by Dima Voichuck on 11/18/20.
//

#include "ush.h"

void mx_parse_ush_manager(t_ush *ush, char *envp[]) {
    if (mx_strcmp(ush->str_input, "exit") == 0) {
        mx_printstr("exit\n");
        ush->event = false;
        exit(1);
    }
    else if(mx_strcmp(ush->str_input, "pwd") == 0) {
        mx_pwd(ush);
    }
    else if(mx_strcmp(ush->str_input, "cd") == 0) {
        mx_cd(ush);
    }
    else if(mx_strcmp(ush->str_input, "env") == 0) {
        mx_env(ush, envp);
    }
    else {
        mx_printstr("ush: command not found: ");
        mx_printstr(ush->str_input);
        mx_printchar('\n');
        free(ush->str_input);
        ush->str_input = NULL;
    }
}
