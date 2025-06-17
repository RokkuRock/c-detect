#include <stdio.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <string.h>

    int main(int argc, char **argv) {
        if (argc < 2) {
            printf("Usage: %s <command>\n", argv[0]);
            return EXIT_FAILURE;
        }

        const char *prefix = "cat ";
        size_t prefixLen = strlen(prefix);

        // Calculate maximum allowed command length after 'cat '
        size_t maxCommandLength = COMMAND_MAX_LENGTH;
        // 假設COMMAND_MAX_LENGTH是已知的最大允许命令長度，若無，可用100或其他合理值
        size_t availableSpace = maxCommandLength - prefixLen;

        // 验证输入是否符合要求
        if (availableSpace == 0 || availableSpace < strlen(argv[1])) {
            printf("Error: Command exceeds maximum allowed length.\n");
            return EXIT_FAILURE;
        }

        // 使用snprintf安全地格式化命令
        char *command = malloc(maxCommandLength * sizeof(char));
        if (!command) {
            perror("malloc failed");
            return EXIT_FAILURE;
        }

        snprintf(command, maxCommandLength, "%s%s", prefix, argv[1]);

        // 執行命令
        if (system(command) == -1) {
            printf("Failed to execute command: %s\n", command);
            free(command);
            return EXIT_FAILURE;
        } else {
            free(command);
        }

        return EXIT_SUCCESS;
    }
