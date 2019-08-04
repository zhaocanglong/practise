#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  int fd = open("./test.txt",O_WRONLY);
  if(fd < 0){
    printf("open error\n");
    exit(1);
  }
  char buff[1024];
  while(1){
     buff[0] = 0;
     printf("client say:");
     fflush(stdout);
     ssize_t s = read(0,buff,sizeof(buff)-1);
     if(s > 0){
       buff[0] = 0;
       write(fd,buff,strlen(buff));
     }
     else{
       exit(3);
     }
  }
  close(fd);
  return 0;
}
