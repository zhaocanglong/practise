#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
//void handler(int sig)
//{
//  pid_t id;
//  while( (id = waitpid(-1, NULL, WNOHANG)) > 0 ){
//    printf("wait child success: %d\n", id);
//
//  }
//  printf("child is quit! %d\n", getpid());
//
//}
//int main()
//{
//  signal(SIGCHLD, handler);
//  pid_t cid;
//  if((cid = fork()) == 0){//child
//  printf("child : %d\n", getpid());
//  sleep(3);
//  exit(1);
//  }
//  while(1){
//    printf("father proc is doing some thing!\n");
//    sleep(1);
//  }

void handler(int sig){
  printf("catch a sig : %d\n",sig);
}

int main(){
  //signal(2,handler);
  //while(1);
  signal(SIGSEGV,handler);
  sleep(1);
  int* p = NULL;
  *p = 10;
  return 0;
}








