//
// Created by Igor Khanenko on 12/8/20.
//

#include "ush.h"

void mx_env_nodes_filling(t_env **env, char **envp) {
    int i = 0;

    for (i = 0; envp[i] != NULL; i++) {
        mx_push_back(&(*env)->env, envp[i]);
    }
    mx_bubble_sort(envp, i);
    (*env)->export_size = i - 1;
//    for (i = 0; envp[i] != NULL; i++)
//        printf("%s\n", envp[i]);
    for (i = 0; envp[i] != NULL; i++) {
        if (strncmp(envp[i], "_=", 2) == 0) {
            i++;
        }
        mx_push_back(&(*env)->export, envp[i]);
    }
//    mx_printchar('\n');
//    while ((*export)) {
//        printf("%s\n", (*export)->data);
//        (*export) = (*export)->next;
//  }
}
