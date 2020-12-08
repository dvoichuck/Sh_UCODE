//
// Created by Igor Khanenko on 12/8/20.
//

#include "ush.h"

void mx_env_nodes_filling(t_list **env, t_list **export, char **envp) {
    int i = 0;

    for (i = 0; envp[i] != NULL; i++) {
        mx_push_back(env, envp[i]);
    }
    mx_bubble_sort(envp, i);
    for (i = 0; envp[i] != NULL; i++)
        printf("%s\n", envp[i]);
}
