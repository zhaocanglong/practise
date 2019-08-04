#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

int main()
{
  int pipefd[2];
  if(pipe(pipefd) < 0){
    perror("pipe error\n");
    exit(EXIT_FAILURE);
  }
  pid_t pid = fork();
  if(pid < 0){
    perror("fork error\n");
    exit(1);
  }
  else if(pid == 0){
    close(pipefd[0]);
    write(pipefd[1],"hello",5);
    close(pipefd[1]);
    exit(EXIT_SUCCESS);
  }
  else{
    close(pipefd[1]);
    char buf[10];
    read(pipefd[0],buf,5);
    printf("buf = %s\n",buf);
    close(pipefd[0]);
  }
  return 0;
}
