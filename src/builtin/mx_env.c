//
// Created by Igor Khanenko on 11/20/20.
//

#include "ush.h"


static bool check_flags(t_list *cmd) {
    bool flag_correct = false;

    return flag_correct;
}

void mx_env(t_ush *ush, t_list *cmd, t_env **env) {
    t_list *node_buf = cmd;
//    extern char **environ;

    if (!cmd->next) {
        t_list *env_buf_node = (*env)->env;
        while (env_buf_node) {
            mx_printstr(env_buf_node->data);
            mx_printchar('\n');
            env_buf_node = env_buf_node->next;
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
