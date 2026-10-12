#incldue < unistd.h>

int main() {
  pid_t pid = fork();

  if (pid) {
    int wstatus = 0;
    if (waitpid(pid, "
