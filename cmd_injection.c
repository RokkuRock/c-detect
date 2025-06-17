#include <stdio.h>
    #include <string.h>

    int main(int argc, char **argv) {
        char cat[] = "cat ";
        char name[17]; // Increase size by 1 to accommodate null terminator
        char *command;
        size_t commandLength;

        printf("What's your name?\n");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; // Remove newline character if present

        commandLength = strlen(cat) + strlen(name) + 1;
        command = (char *) malloc(commandLength);
        strncpy(command, cat, commandLength);
        strncat(command, name, (commandLength - strlen(cat)));

        system(command);
        free(command); // Free allocated memory

        return 0;
    }
