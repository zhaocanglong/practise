#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<pthread.h>
#include<sched.h>

int ticket =5000;
pthread_mutex_t mutex;

void *thread(void* arg){
  char* id = (char*)arg;
  while(1){
    pthread_mutex_lock(&mutex);
    if(ticket > 0){
      usleep(1);
      printf("%s sells the ticket : %d\n",id,ticket);
      ticket--;
      pthread_mutex_unlock(&mutex);
    }
    else {
      pthread_mutex_unlock(&mutex);
      break;
    }
  }
}

int main(){
  pthread_t t1,t2,t3,t4;
  pthread_mutex_init(&mutex,NULL);
  pthread_create(&t1,NULL,thread,"thread 1");
  pthread_create(&t2,NULL,thread,"thread 2");
  pthread_create(&t3,NULL,thread,"thread 3");
  pthread_create(&t4,NULL,thread,"thread 4");

  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  pthread_join(t3,NULL);
  pthread_join(t4,NULL);
  pthread_mutex_destroy(&mutex);
  return 0;
}
