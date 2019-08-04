#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  int fd = open("./test.txt",O_RDONLY);
  if(fd < 0){
    printf("open error\n");
    exit(1);
  }
  char buff[1024];
  while(1){
     buff[0] = 0;
     printf("please wait....\n");
     fflush(stdout);
     ssize_t s = read(fd,buff,sizeof(buff)-1);
     if(s > 0){
       buff[s-1] = 0;
       printf("client say: %s \n",buff);
     }
     else if(s == 0){
       printf("client quit,exit now\n");
       exit(4);
     }
     else{
       exit(3);
     }
  }
  close(fd);
  return 0;
}
