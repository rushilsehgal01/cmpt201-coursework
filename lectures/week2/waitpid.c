#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid == 0) {
    printf("CHILD: we need to wait for pid: %d\n", getpid());
    execlp("ls", "ls", "-a", "-l", NULL);
  } else {
    int wstatus = 0;
    pid_t wait = waitpid(pid, &wstatus, 0);
    if (wait == -1) {
      printf("waitpid failed");
      return -1;
    }
    printf("child done and pid we were waiting for is %d\n", wait);
  }
}
