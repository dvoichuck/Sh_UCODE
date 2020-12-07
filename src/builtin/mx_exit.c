//
// Created by Dima Voichuck on 12/7/20.
//

#include "ush.h"

static void check_for_data(char *str, t_list **new_list) {
    int i;

    if ((*new_list)->next != NULL)
        mx_printerr("exit: too many arguments\n");
    else {
        system("leaks -q ush");
        errno = 0;
        if (!mx_isdigit(str[0])) {
            mx_printstr("exit\n");
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
                exit(errno);
            }
        errno = mx_atoi(str);
        exit(errno);
    }
}

void mx_exit(t_ush *ush, t_list **new_list) {
    (*new_list) = (*new_list)->next;
    if ((*new_list))
        check_for_data((*new_list)->data, new_list);
    else {
        mx_printstr("exit\n");
        ush->event = false;
        exit(errno);
    }
}
