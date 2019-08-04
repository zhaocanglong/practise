#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#define MAX_CMD 1024
char command[MAX_CMD];

int do_face(){
  memset(command,0x00,MAX_CMD);
  printf("minishell$");
  fflush(stdout);
  if(scanf("%[^\n]%*c",command) == 0){
    exit(1);
  }
  return 0;
}

char** do_parse(char* buff){
  int argc = 0;
  static char* argv[32];
  char* ptr = buff;
  while(*ptr != '\0'){
    if(!isspace(*ptr)){
      argv[argc++] = ptr;
      while(!isspace(*ptr) && (*ptr) != '\0'){
        ptr++;
      }
    }
    else{
      while(isspace(*ptr)){
        *ptr = '\0';
        ptr++;
      }
    }
  }
  argv[argc] = NULL;
  return argv;
}

int do_exec(char *buff){
  char** argv = {NULL};
  pid_t pid = fork();
  if(pid < 0){
    perror("fork error");
  }
  else if(pid == 0){
    argv = do_parse(buff);
    if(argv[0] == NULL){
      exit(2);
    }
    execvp(argv[0],argv);
  }
  else{
    waitpid(pid, NULL,0);
  }
}

int main(){
  while(1){
    if(do_face() < 0){
      continue;
    }
    do_exec(command);
  }
  return 0;
}
