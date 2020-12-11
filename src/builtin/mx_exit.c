//
// Created by Dima Voichuck on 12/7/20.
//

#include "ush.h"

static void check_for_data(t_ush *ush, t_env *env, t_list **new_list,
                           char *str) {
    int i;

    if ((*new_list)->next != NULL)
        mx_printerr("exit: too many arguments\n");
    else {
        system("leaks -q ush");
        errno = 0;
        if (!mx_isdigit(str[0])) {
            mx_printstr("exit\n");
            mx_free_memory(&ush, &env, new_list);
            exit(errno);
        }
        for (i = 0; str[i] != '\0'; i++)
            if (!mx_isdigit(str[i])) {
                char *tmp = mx_substr(str, i, mx_strlen(str));
                mx_printerr(
                        "u$h: bad math expression: operator expected at '");
                mx_printerr(tmp);
                mx_printerr("'\n");
                free(tmp);
                mx_free_memory(&ush, &env, new_list);
                exit(errno);
            }
        errno = mx_atoi(str);
        mx_free_memory(&ush, &env, new_list);
        exit(errno);
    }
}

void mx_exit(t_ush *ush, t_env *env, t_list **new_list) {
    (*new_list) = (*new_list)->next;
    if ((*new_list))
        check_for_data(ush, env, new_list, (*new_list)->data);
    else {
        mx_printstr("exit\n");
        ush->event = false;
        mx_free_memory(&ush, &env, new_list);
        system("leaks -q ush");
        exit(errno);
    }
}
