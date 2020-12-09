#include "ush.h"

static int tmain(int argc, char **argv, char **envp);

int main(int argc, char *argv[], char *envp[]) {
//    system("leaks -q ush");
    return tmain(argc, argv, envp);
}

static int tmain(int argc, char **argv, char **envp) {
//    t_list *test = NULL;
//    t_list *test_2 = NULL;
//    t_list *test_3 = NULL;
//    char *one = mx_strdup("One");
//    char *two = mx_strdup("Two");
//    char *three = mx_strdup("Three");
//    char *four = mx_strdup("Four");
//    char *five = mx_strdup("Five");
//    int i = 0;
//
//    mx_push_back(&test, one);
//    mx_push_back(&test, two);
//    mx_push_back(&test, three);
//
//    test_2 = test;
//    while (test_2) {
//        printf("List #%d = %s\n", i++, test_2->data);
//        test_2 = test_2->next;
//    }
//
//    mx_push_penultimate(&test, five);
//    mx_push_penultimate(&test, four);
//
//    i = 0;
//    test_3 = test;
//    while (test_3) {
//        printf("List #%d = %s\n", i++, test_3->data);
//        test_3 = test_3->next;
//    }
    mx_signals();
    mx_input(envp);

    return errno;
}
