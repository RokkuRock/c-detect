#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void safeCat(const char* filename) {
    pid_t pid = fork();
    if (pid == 0) { // Child process
        execlp("cat", "cat", filename, NULL);
        perror("Failed to execute 'cat'");
        exit(-1);
    } else if (pid > 0) { // Parent process
        int status;
        wait(&status);
        if (WIFEXITED(status) && WEXITSTATUS(status)!= 0) {
            fprintf(stderr, "'cat %s' failed with exit code %d\n", filename, WEXITSTATUS(status));
        }
    } else { // Fork failed
        perror("Fork failed");
    }
}

int main(int argc, char **argv) {
    if (argc <= 1) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return (-1);
    }
    safeCat(argv[1]);
    return (0);
}
