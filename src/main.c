#include "ush.h"

static int tmain(int argc, char *argv[], char *envp[]);

int main(int argc, char *argv[], char *envp[]) {

//    system("leaks -q ush");
    return tmain(argc, argv, envp);
}

static int tmain(int argc, char *argv[], char *envp[]) {
    mx_input(envp);
    return 1;

}
