//
// Created by Igor Khanenko on 11/20/20.
//

#include "ush.h"

void mx_cd(t_ush *ush, char *path) {
    char *path_buf = !path ? ush->home : path;
    int result;

    result = chdir(path_buf);
    if (result != 0)
        printf("Не могу перейти к каталогу %s\n", path_buf);
    else
        printf("Текущим стал каталог %s\n", path_buf);



//    int fd;
//    struct stat sbuf;
//
//    fd = open(".", O_RDONLY); /* открыть каталог для чтения */
//    fstat(fd, &sbuf); /* получить сведения, нужны начальные права доступа */
//    chdir(argv_dir); /* 'cd ..' */
//    fchmod(fd, 0); /* отменить права доступа каталога */
//
//    if (fchdir(fd) < 0) /* попытаться выполнить 'cd' обратно, должно завершиться неудачей */
//        perror("fchdxr back");
//
//    fchmod(fd, sbuf.st_mode & 07777); /* восстановить первоначальные права доступа */
//    close(fd); /* все сделано */
}
