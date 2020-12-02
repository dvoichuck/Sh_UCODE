//
// Created by mac on 01.12.2020.
//

#include "ush.h"

static void sig(int sig) {
    sig = sig + 1 - 1;
}

void mx_signals() {
    signal(SIGTSTP, sig);
    signal(SIGINT, sig);
    signal(SIGTTOU, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);
}
