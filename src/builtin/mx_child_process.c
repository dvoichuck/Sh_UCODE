//
// Created by mac on 29.11.2020.
//

#include "ush.h"


void mx_child_process(t_ush *ush, char **path, char **envp) {
    int status = 0;
    pid_t pid = fork();

    if (pid == 0) {
        if (execve(path[0], path, envp) == -1) {
            mx_printerr("Ошибка запуска утилиты!\n");
            exit(errno);
        }
    }
    else {
        waitpid(pid, &status, WUNTRACED);
        if (WEXITSTATUS(status) == 1)
            errno = 1;
        else
            errno = 0;
//        if (status == 4735) {
//            mx_printchar('\n');
//            errno = 130;
//            exit(errno);
//        }
    }
}
