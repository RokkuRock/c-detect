#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc <= 1) {
        printf("Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t len = strlen(argv[1]);
    char *cmd = calloc(len+5, sizeof(*cmd));
    sprintf(cmd, "cat %s", argv[1]);

    system(cmd);
    free(cmd);
    return EXIT_SUCCESS;
}
