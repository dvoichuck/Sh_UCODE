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
            str = mx_charjoin(str, ch);
        }
        if (ch == 'q') {
//            printf("%s", str);
//            write(1, "exit\n", 5);
            break;
        }
        else
            write(1, &ch, 1);
        switch (ch) {
            case 65:
                printf("%c[1A", 27);
                fflush(stdout);
                break;
            case 66:
                printf("%c[1B", 27);
                fflush(stdout);
                break;
            case 67:
                printf("%c[1C", 27);
                fflush(stdout);
                break;
            case 68:
                printf("%c[1D", 27);
                fflush(stdout);
                break;

        }
    }
    printf("%s", str);
    tcsetattr(0, TCSAFLUSH, &savetty);
}
