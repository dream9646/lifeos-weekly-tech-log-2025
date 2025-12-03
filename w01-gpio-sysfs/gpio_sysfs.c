
#include <errno.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 

int main(int argc,char *argv[]){ 
  if(argc!=2){ 
    printf("please only input one number\n"); 
    return 1; 
  } 
  
  int gpio = atoi(argv[1]); 
  char buf[16]; 
  char path[64]; 
  int len=0; 
  
  snprintf(buf,sizeof(buf),"%d",gpio); 
  snprintf(path,sizeof(path),"/tmp/gpio/export"); 
  
  int fd=open(path,O_WRONLY); 
  if(fd<0){ 
    printf("open fail"); 
  } 
  write(fd,buf,strlen(buf)); 
  close(fd); sleep(1); 
  snprintf(buf,sizeof(buf),"out"); 
  snprintf(path,sizeof(path),"/tmp/gpio/gpio%d/direction",gpio); 
  fd=open(path,O_WRONLY); 
  if(fd<0){ 
    printf("open fail"); 
  } 
  write(fd,buf,strlen(buf)); 
  close(fd); 
  snprintf(buf,sizeof(buf),"1"); 
  snprintf(path,sizeof(path),"/tmp/gpio/gpio%d/value",gpio); 
  fd=open(path,O_WRONLY); 
  if(fd<0){ 
    printf("open fail"); 
  } 
  write(fd,buf,strlen(buf)); 
  close(fd); 
  
  sleep(1); 
  
  fd=open(path,O_RDONLY); 
  if(fd<0){ 
    printf("open fail"); 
  } 
  int n = read(fd,buf,sizeof(buf)-1); 
  if(n<0){ 
    printf("read fail"); 
  } 
  buf[n]='\0'; 
  close(fd); 
  printf("Read back value:%s\n",buf); 
  return 0; 
}
