//
// Created by Igor Khanenko on 12/10/20.
//

#include "ush.h"

 static bool cmp_sort_list(void *a, void *b) {
    return mx_strcmp(a, b) > 0 ? true : false;
 }

void mx_refilling_env(t_env **env, char *env_var) {
    char *env_var_buf = mx_strdup(env_var);

    mx_push_penultimate(&(*env)->env, env_var_buf);
    mx_push_back(&(*env)->export, env_var_buf);
    mx_sort_list((*env)->export, cmp_sort_list);
}
