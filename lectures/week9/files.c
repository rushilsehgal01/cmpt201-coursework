#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  char *str = "hello world";
  char buf[12];

  int fd = open("tmp", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

  write(fd, str, strlen(str));

  lseek(fd, -6, SEEK_CUR);
  int s = read(fd, buf, 6);

  write(STDOUT_FILENO, buf, s);

  close(fd);
}
