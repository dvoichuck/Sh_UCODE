//
// Created by mac on 01.12.2020.
//

#include "ush.h"

static void sigcatch(int sig) {
    sig = 1;
    mx_printstr("\n");
}


void mx_signals() {
    signal(SIGTSTP, sigcatch);
    signal(SIGINT, sigcatch);
    signal(SIGTTOU, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);
}
