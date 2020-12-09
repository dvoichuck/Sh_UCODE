//
// Created by Dima Voichuck on 11/16/20.
//

#include "ush.h"

void mx_input(t_env *env) {
    t_ush *ush = (t_ush *)malloc(sizeof(t_ush));
    t_list *input = NULL;
//    struct termios tty;
//    struct termios savety;
//
//    tcgetattr(0, &tty);
//    savety = tty;

    ush->ch = '\0';

    mx_initialization_struct(ush);
    ush->home = getenv("HOME");
    ush->user = getenv("USER");

//    printf("Home directory: \"%s\"\n", ush->home);
//    printf("User name: \"%s\"\n", ush->user);
//    setvbuf(stdout,NULL,_IONBF,0);
//
//    struct termios old_termios, new_termios;
//    tcgetattr(0,&old_termios);


//    signal( SIGINT, sig_hnd );
//
//    new_termios             = old_termios;
//    new_termios.c_cc[VEOF]  = 3; // ^C
//    new_termios.c_cc[VINTR] = 4; // ^D
//    tcsetattr(0,TCSANOW,&new_termios);
    write(1, "u$h> ", 5);
    ush->ch = '\0';
    while (ush->event) {
        if (read(0, &ush->ch, 1) > 0) {
            mx_filling_str_with_input(ush, ush->ch);
//        mx_non_canon_mode();
//        tcsetattr(0, TCSAFLUSH, &tty);
        }
        if (ush->ch == '\n') {
            mx_parse_ush_manager(&input, ush, env);
            if (ush->ch != '\0')
                write(1, "u$h> ", 5);
        }
    }
//    tcsetattr(0,TCSANOW,&old_termios);
}
