//
// Created by Igor Khanenko on 12/8/20.
//

#include "ush.h"



void mx_non_canon_mode(void) {
    struct termios term;

    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    term.c_cc[VMIN] = 1;
    term.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);

//    struct termios tattr;
//
//    /* Save the terminal attributes so we can restore them later. */
//    tcgetattr (STDIN_FILENO, &saved_attributes);
//
//    /* Set the funny terminal modes. */
//    tcgetattr (STDIN_FILENO, &tattr);
//    tattr.c_lflag &= ~(ICANON|ECHO); /* Clear ICANON and ECHO. */
//    tcsetattr (STDIN_FILENO, TCSAFLUSH, &tattr);
}
