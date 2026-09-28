#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  char *input = NULL;
  size_t n = 0;

  while (1) {
    printf("Enter programs to run. \n");
    printf("> ");
    ssize_t length = getline(&input, &n, stdin);
    if (length == -1) {
      perror("failed to read line\n");
      break;
    }
    if (length > 0 && input[length - 1] == '\n')
      input[length - 1] = '\0';

    pid_t cpid = fork();
    if (cpid < 0) {
      perror("fork failed\n");
      continue;
    } else if (cpid > 0) {
      int status = 0;
      if (waitpid(cpid, &status, 0) == -1) {
        perror("waitpid failed \n");
        exit(EXIT_FAILURE);
      }
      if (WIFEXITED(status)) {
        printf("child existed \n");
      }
    } else {
      if (execl(input, input, (char *)NULL) == -1) {
        perror("execution of child process (execl failed)\n");
        free(input);
        exit(EXIT_FAILURE);
      }
    }
  }
  free(input);
  return 0;
}
