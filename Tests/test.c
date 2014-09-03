#include <stdio.h>
#include <pthread.h>
#define NUM_THDS 8
int x;
int y;

int bar(int wang){
  return wang * wang;
}

int foo(int thing){
  return bar(thing * thing);
}

void *thread_main(void *p){

  for(int i = 0; i < 10000; i++ ){

    x+= i;    

  }
  return NULL;
}

int main(int argc, char *argv[]){
  
  x = 10;
  y = 20;

  int z = foo(x);
  y = bar(y);

  pthread_t thd[NUM_THDS];
  for( int i = 0 ; i < NUM_THDS; i++ ){
    pthread_create(&(thd[i]),NULL,thread_main,NULL);
  }
  for( int i = 0 ; i < NUM_THDS; i++ ){
    pthread_join(thd[i],NULL);
  }
  

  fprintf(stderr,"%d %d\n",z,y);

}
