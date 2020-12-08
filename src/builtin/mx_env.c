//
// Created by Igor Khanenko on 11/20/20.
//

#include "ush.h"


static bool check_flags(t_list *cmd) {
    bool flag_correct = false;

    return flag_correct;
}

void mx_env(t_ush *ush, t_list *cmd, char **envp) {
    t_list *node_buf = cmd;
    extern char **environ;

    if (!cmd->next) {
        for (int i = 0; environ[i] != NULL; i++) {
            mx_printstr(environ[i]);
            mx_printchar('\n');
        }
    }
    else {
        node_buf->next = node_buf;
        if (strncmp(cmd->data, "-", 1) == 0) {
            if (check_flags(node_buf) == true) {

            }
        }
    }
}
