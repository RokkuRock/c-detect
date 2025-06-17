#include <stdio.h>
    #include <string.h>
    #include <unistd.h>

    #define MAX_COMMAND_LENGTH 100

    int validateCommand(const char* cmd){
      if(strlen(cmd) > MAX_COMMAND_LENGTH){
          return 0;
      }
      // Add more checks here to prevent dangerous commands

      return 1;
    }

    int main(int argc, char **argv) {
      if(argc < 2){
         printf("Usage:./program <command>\n");
         return 1;
      }

      if(!validateCommand(argv[1])){
         printf("Invalid command.\n");
         return 1;
      }

      system(argv[1]);
      return 0;
    }
