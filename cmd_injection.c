#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc!= 2 || strcmp(argv[1], "FILE")!= 0) {
        printf("Usage: %s FILE\n", argv[0]);
        return 1;
    }

    char *command = malloc(strlen("cat ") + strlen(argv[1]) + 2);
    snprintf(command, sizeof(command), "cat %s", argv[1]);

    pid_t child = fork();
    if (child == -1) {
        perror("fork failed");
        return 1;
    }
    if (child!= 0) {
        waitpid(child, 0, WNOHANG);
    }

    system(command);
    free(command);
    return 0;
}
