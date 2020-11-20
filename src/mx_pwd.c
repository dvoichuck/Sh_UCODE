//
// Created by Igor Khanenko on 11/19/20.
//

#include "ush.h"

void mx_pwd (t_ush *ush) {
    char path_buf[MAX_LEN];

    getcwd(path_buf, MAX_LEN);
    mx_printstr(path_buf);
    mx_printchar('\n');
    free(path_buf);
}
