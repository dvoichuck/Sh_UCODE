#include "ush.h"

static int tmain(int argc, char *argv[]);

int main(int argc, char *argv[]) {

//    system("leaks -q ush");
    return tmain(argc, argv);
}

static int tmain(int argc, char *argv[]) {
    mx_input();
    return 1;

}
