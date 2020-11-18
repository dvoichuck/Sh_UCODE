//
// Created by Dima Voichuck on 11/16/20.
//

#include "ush.h"

void mx_input(void) {
    struct termios savetty;
    struct termios tty;
    char ch;
    char *str = NULL;

    tcgetattr(0, &tty);
    savetty = tty;
    tty.c_lflag &= ~(ICANON | ECHO | ISIG);
    tty.c_cc[VMIN] = 1;
    tcsetattr(0, TCSAFLUSH, &tty);

    for (;;) {
        if (read(0, &ch, 1)) {
            printf("1");
            str = mx_charjoin(str, ch);
            }
        if (ch == 'q') {
            write(1, "\nexit\n", 6);
            break;
        }
        else
            write(1, &ch, 1);
        }
    printf("%s", str);
    tcsetattr(0, TCSAFLUSH, &savetty);
}
