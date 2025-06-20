#include <stdio.h>
#include <unistd.h>
#define BUFSIZER1 512
#define BUFSIZER2 ((BUFSIZER1/2) - 8)
int main(int argc, char **argv) {
    char *buf1R1;
    char *buf2R1;
    char *buf2R2;
    char *buf3R2;

    buf1R1 = (char *) malloc(BUFSIZER1);
    buf2R1 = (char *) malloc(BUFSIZER1);
    free(buf2R1);
    buf2R2 = (char *) malloc(BUFSIZER2);
    buf3R2 = (char *) malloc(BUFSIZER2);

    // Fix: 使用新的指针进行strncpy操作
    char *new_buf = (char *) malloc(BUFSIZER1);
    strncpy(new_buf, argv[1], BUFSIZER1 - 1);
    free(buf1R1);
    free(buf2R2);
    free(buf3R2);
    free(new_buf);

    return 0;
}
