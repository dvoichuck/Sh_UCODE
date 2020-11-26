//
// Created by Igor Khanenko on 11/20/20.
//

#include "ush.h"



void mx_env(t_ush *ush, char *envp[]) {

    for (int i = 0; envp[i] != NULL; i++) {
        mx_printstr(envp[i]);
        mx_printchar('\n');
    }
}
