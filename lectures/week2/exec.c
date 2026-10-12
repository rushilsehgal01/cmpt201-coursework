#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid == 0) {
    printf("CHILD: PID=%d, parent PID=%d\n", getpid(), getppid());
    // execl("/bin/ls", "bin/ls", "-alh", NULL);
    // execlp("ls", "ls", "-a", NULL);
    // char* const args[] = {"ls", "-a", 0};
    // execvp("ls", args);
    char *args[] = {"echo", "hello", "world", NULL};
    execvp("echo", args);
  } else {
    printf("PARENT: PID=%d, child PID=%d\n", getpid(), pid);
    // execl("/bin/ls", "bin/ls", "-a", NULL);
    execlp("ls", "ls", "-a", "-l", "-h", NULL);
  }
}
