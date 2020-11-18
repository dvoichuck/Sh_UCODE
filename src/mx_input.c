//
// Created by Dima Voichuck on 11/16/20.
//

#include "ush.h"

void mx_input(void) {
//    struct termios savetty;
//    struct termios tty;
    char ch = '\0';

    t_ush *ush = (t_ush *)malloc(sizeof(t_ush));
    mx_initialization_struct(ush);
//    tcgetattr(0, &tty);
//    savetty = tty;
//    tty.c_lflag &= ~(ICANON | ECHO | ISIG);
//    tty.c_cc[VMIN] = 1;
//    tcsetattr(0, TCSAFLUSH, &tty);
    write(1, "u$h> ", 5);
    for (;;) {
        if (read(0, &ch, 1)) {
            mx_filling_str_with_input(ush, ch);
        }
        if (ch == '\n')
            write(1, "u$h> ", 5);
        else if (ch == 'q') {
            write(1, "u$h> ", 5);
            write(1, "exit\n", 6);
            break;
        }
    }
    printf("%s", ush->str_input);
//    tcsetattr(0, TCSAFLUSH, &savetty);
}
