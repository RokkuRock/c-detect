#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFSIZE 100
#define FLAGSIZE 64

void win(unsigned int arg1, unsigned int arg2) {
  char buf[FLAGSIZE];
  FILE *f = fopen("flag.txt","r");
  if (f == NULL) {
    printf("Flag File is Missing. Problem is Misconfigured, please contact an Admin if you are running this on the shell server.\n");
    exit(0);
  }

  fgets(buf,FLAGSIZE,f);
  if (arg1 == 0xDEADBEEF && arg2 == 0xDEADC0DE) // 更改比較運算子以避免格式化字符串攻擊
    printf(buf);
}

void vuln(){
  char buf[BUFSIZE];
  read(0, buf, BUFSIZE); // 使用 read 而不是 gets 以防止 buffer overflow
  write(1, buf, strlen(buf)); // 使用 write 而不是 puts 以避免格式化字符串攻擊
}

int main(int argc, char **argv){

  setvbuf(stdin, NULL, _IONBF, 0); // 禁用 stdin 的 buffer
  setvbuf(stdout, NULL, _IONBF, 0); // 禁用 stdout 的 buffer

  gid_t gid = getegid();
  setresgid(gid, gid, gid);

  puts("Please enter your string: ");
  vuln();
  return 0;
}
