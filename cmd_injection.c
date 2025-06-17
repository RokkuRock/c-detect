#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // 定义允许的字符集，禁止Shell元字符
    const char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-";
    size_t max_length = 100; // 防止過長輸入

    // 輔入並檢查檔案存在性
    FILE* user_file = fopen(argv[1], "r");
    if (!user_file) {
        printf("Error: 檔案不存在\n");
        return EXIT_FAILURE;
    }
    fclose(user_file);

    // 使用snprintf安全地構建命令
    char command[200]; // 增加緩衝區大小
    size_t written = snprintf(command, sizeof(command),
                            "cat '%s'", argv[1]);

    if (written == EOF || written > sizeof(command)-1) {
        printf("Error: 檔案讀取失敗或太長\n");
        return EXIT_FAILURE;
    }

    system(command);
    free(command); // 釋放_malloc得到的記憶體
    return EXIT_SUCCESS;
}
