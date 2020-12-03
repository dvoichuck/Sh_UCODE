//
// Created by Dima Voichuck on 11/16/20.
//

#include "ush.h"

void sig_hnd(int sig){ (void)sig; printf("(VINTR)"); }

void mx_input(char **envp) {
    char ch = '\0';

    t_ush *ush = (t_ush *)malloc(sizeof(t_ush));
    t_list *input = NULL;
    mx_initialization_struct(ush);
//    setvbuf(stdout,NULL,_IONBF,0);
//
//    struct termios old_termios, new_termios;
//    tcgetattr(0,&old_termios);
//
//    signal( SIGINT, sig_hnd );
//
//    new_termios             = old_termios;
//    new_termios.c_cc[VEOF]  = 3; // ^C
//    new_termios.c_cc[VINTR] = 4; // ^D
//    tcsetattr(0,TCSANOW,&new_termios);
    write(1, "u$h> ", 5);
    while (ush->event) {
        if (read(0, &ch, 1) > 0) {
            mx_filling_str_with_input(ush, ch);
        }
        if (ch == '\n') {
            mx_parse_ush_manager(&input, ush, envp);
            write(1, "u$h> ", 5);
        }
    }
//    tcsetattr(0,TCSANOW,&old_termios);
}
