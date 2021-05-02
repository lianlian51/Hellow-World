#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
  int fifo = mkfifo("./mkfifo_test", 0664);
  if(fifo <0)
  {
    printf("mkdifo error\n");
    return -1;
  }

  char buf[] = "i love you\n";
  int fd = open("./mkfifo_test", O_RDWR);
  write(fd, buf, sizeof(buf) - 1);

  char buf2[1024] = {0};
  read(fd, buf2, sizeof(buf2) - 1);

  printf("%s", buf2);

  return 0;
}
