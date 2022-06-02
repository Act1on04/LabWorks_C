#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

extern char **environ;

int main()
{
  char *cat_args[] = {"cat", "/etc/hosts", NULL};

  pid_t pid = fork();
  if (pid == 0)
  {
    printf("\nThe child of Ischenko print next info:\n");
    execve("/bin/cat", cat_args, environ);
    printf("execve failed\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}