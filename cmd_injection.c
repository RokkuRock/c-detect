#include <iostream>
    #include <string.h>
    int main(int argc, char **argv) {
      if(argc < 2){
          std::cout << "Usage:./program cmd\n";
          return 1;
      }

      const size_t maxCommandSize = 100;
      char command[maxCommandSize];
      snprintf(command, maxCommandSize, "cat %s", argv[1]);
      system(command);
      return 0;
    }
