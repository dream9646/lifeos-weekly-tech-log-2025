#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char *argv[]){
	if( argc < 4 ){
		printf("./gpio_led_toggle [gpio] [count] [deley_ms]\n");
		return EXIT_FAILURE;
	}
	char path[64];
	char buf[16];
	int gpio = atoi(argv[1]);
	int count = atoi(argv[2]);
	int deley_ms = atoi(argv[3])*1000;

	//export
	snprintf(path,sizeof(path),"/tmp/gpio/export");
	snprintf(buf,sizeof(buf),"%d",gpio);
	int fd = open(path,O_WRONLY);
	if( fd < 0 ){
		perror("Open export failed");
		return EXIT_FAILURE;
	}
	ssize_t len = (ssize_t)strlen(buf);
	ssize_t written = write(fd,buf,len);
	if( len != written ){
		perror("Write failed");
		return EXIT_FAILURE;
	}
	close(fd);
	usleep(50*1000);
	//direction
	snprintf(path,sizeof(path),"/tmp/gpio/gpio%d/direction",gpio);
	snprintf(buf,sizeof(buf),"out");
	fd = open(path,O_WRONLY);
	if( fd < 0 ){
		perror("Open direction failed");
		return EXIT_FAILURE;
	}
	len = (ssize_t)strlen(buf);
	written = write(fd,buf,len);
	if( len != written ){
		perror("Write failed");
		return EXIT_FAILURE;
	}
	close(fd);
	//toggle
	for(int i=0;i<count;i++){
		printf("Do count:%d\n",i);
		snprintf(path,sizeof(path),"/tmp/gpio/gpio%d/value",gpio);
		snprintf(buf,sizeof(buf),"1");
		fd = open(path,O_WRONLY);
		if ( fd < 0 ){
			perror("Open value failed");
			return EXIT_FAILURE;
		}
		len = (ssize_t)strlen(buf);
		written = write(fd,buf,len);
		if( len != written ){
			perror("Write failed");
			return EXIT_FAILURE;
		}
		close(fd);
		usleep(deley_ms);
		
		fd = open(path,O_WRONLY);
		if( fd < 0 ){
			perror("Open value failed");
			return EXIT_FAILURE;
		}
		snprintf(buf,sizeof(buf),"0");
		len = (ssize_t)strlen(buf);
		written = write(fd,buf,len);
		if( len != written ){
			perror("Write failed");
			return EXIT_FAILURE;
		}
		close(fd);
		usleep(deley_ms);
	}
	//unexport
	snprintf(path,sizeof(path),"/tmp/gpio/unexport");
	snprintf(buf,sizeof(buf),"%d",gpio);
	fd = open(path,O_WRONLY);
	if( fd < 0 ){
		perror("Open unexport failed");
		return EXIT_FAILURE;
	}
	len = (ssize_t)strlen(buf);
	written = write(fd,buf,len);
	if( len != written ){
		perror("Write failed");
		return EXIT_FAILURE;
	}
	close(fd);

	return EXIT_SUCCESS;
}
