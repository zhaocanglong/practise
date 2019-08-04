#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
 // FILE* fp = fopen("./test.txt","w");
 // if(!fp){
 //   perror("fopen error");
 // }
 // const char* msg = "hello bits\n";
 // int count = 5;
 // while(count--){
 //   fwrite(msg,strlen(msg),1,fp);
 // }
 // fclose(fp);
 // umask(0);
 // int fd = open("./test.txt",O_WRONLY| O_CREAT,0664);
 // if(fd < 0){
 //   perror("open error\n");
 //   return -1;
 // }
 // int count = 5;
 // const char* msg = "helo world\n";
 // int len = strlen(msg);
 // while(count--){
 //   write(fd,msg,len);
 // }
 // close(fd);
 // return 0;
  umask(0);
  int fd = open("./test.txt",O_RDONLY);
  if(fd < 0){
    perror("open error\n");
    return -1;
  }
  const char* msg = "helo world\n";
  char buff[1024];
  int len = strlen(msg);
  while(1){
    ssize_t s = read(fd,buff,len);
    if(s > 0){
      printf("%s",buff);
    }
    else{
      break;
    }
  }
  close(fd);
  return 0;
}
