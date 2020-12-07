//
// Created by Igor Khanenko on 12/3/20.
//

#include "ush.h"

static void output_str_create() {

}

void mx_echo(t_ush *ush, t_list *cmd) {
    t_list *node_buf = cmd;
    char *err = NULL;
    int status = 0;

    if (node_buf->next) {
        node_buf = node_buf->next;
        if (strcmp(node_buf->data, "$?") == 0) {
            err = mx_itoa(errno);
            status = write(1, err, strlen(err));
        }
        else
            status = write(1, node_buf->data, strlen(node_buf->data));
        write(1, "\n", 1);
        errno = status != 0 ? 1 : 0;
    }
    else
        mx_printchar('\n');
    free(err);
}
