//
// Created by Igor Khanenko on 12/10/20.
//

#include "ush.h"

void mx_free_memory(t_ush **ush, t_env **env, t_list **cmd) {
//    while (cmd) {
//        if (malloc_size((*cmd)->data))
//            free((*cmd)->data);
//        mx_pop_front(&(*cmd));
//    }
    while ((*env)->env) {
        if (malloc_size((*env)->env->data))
            free((*env)->env->data);
        mx_pop_front(&(*env)->env);
    }
    while ((*env)->export) {
        if (malloc_size((*env)->export->data))
            free((*env)->export->data);
        mx_pop_front(&(*env)->export);
    }
    if (malloc_size(env))
        free(env);
    if (malloc_size((*ush)->str_input))
        free((*ush)->str_input);
    if (malloc_size(ush))
        free(ush);
}
