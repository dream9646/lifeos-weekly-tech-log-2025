#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define GPIO_BASE "/tmp/gpio"

static int gpio_export(int gpio){
	char buf[16];
	char path[64];

	snprintf(path, sizeof(path), GPIO_BASE "/export");
	
	int fd = open(path, O_WRONLY);
	if( fd < 0 ){
		perror("open export");
		return EXIT_FAILURE;
	}

	snprintf(buf, sizeof(buf), "%d", gpio);
	
	ssize_t len = (ssize_t)strlen(buf);
	ssize_t written = write(fd, buf, len);
	if( len != written ){
		perror("write gpio");
		close(fd);
		return EXIT_FAILURE;
	}

	close(fd);
	return EXIT_SUCCESS;
}

static int gpio_set_direction(int gpio, const char *dir){
	char path[64];
	char buf[16];

	snprintf(path, sizeof(path), GPIO_BASE "/gpio%d/direction", gpio);
	int fd = open(path,O_WRONLY);
	if(fd < 0){
		perror("open direction");
		return EXIT_FAILURE;
	}

	snprintf(buf, sizeof(buf), "%s", dir);
	ssize_t len = (ssize_t)strlen(buf);
	ssize_t written = write(fd, buf, len);
	if(len != written){
		perror("write direction");
		close(fd);
		return EXIT_FAILURE;
	}
	
	close(fd);
	return EXIT_SUCCESS;
}

static int gpio_write_value(int gpio, int value){
	char path[64];
	char buf[4];

	snprintf(path, sizeof(path), GPIO_BASE "/gpio%d/value", gpio);
	int fd = open(path, O_WRONLY);
	if(fd < 0){
		perror("open value");
		return EXIT_FAILURE;
	}

	buf[0] = (value ? '1' : '0');
	buf[1] = '\0';
	
	ssize_t len = (ssize_t)strlen(buf);
	ssize_t written = write(fd, buf, len);
	if(len != written){
		perror("write value");
		close(fd);
		return EXIT_FAILURE;
	}

	close(fd);
	return EXIT_SUCCESS;
}

static int gpio_unexport(int gpio){
	char path[64];
	char buf[16];

	snprintf(path, sizeof(path), GPIO_BASE "/unexport");
	int fd = open(path, O_WRONLY);
	if(fd < 0){
		perror("open unexport");
		return EXIT_FAILURE;
	}
	
	snprintf(buf, sizeof(buf), "%d", gpio);
	ssize_t len = (ssize_t)strlen(buf);
	ssize_t written = write(fd, buf, len);
	if(len != written){
		perror("write unexport");
		close(fd);
		return EXIT_FAILURE;
	}

	close(fd);
	return EXIT_SUCCESS;
}

int main(int argc,char *argv[]){
	if( argc < 4 ){
		printf("Usage:%s [gpio] [count] [deley_ms]\n", argv[0]);
		return EXIT_FAILURE;
	}
	int gpio = atoi(argv[1]);
	int count = atoi(argv[2]);
	int delay_ms = atoi(argv[3])*1000;

	//export
	if(gpio_export(gpio) != EXIT_SUCCESS){
		return EXIT_FAILURE;
	}

	//direction
	if(gpio_set_direction(gpio, "out") != EXIT_SUCCESS){
		return EXIT_FAILURE;
	}

	//toggle
	for(int i=0;i<count;i++){
		printf("Do count:%d\n", i);
		if(gpio_write_value(gpio, 1) != EXIT_SUCCESS){
			return EXIT_FAILURE;
		}
		usleep(delay_ms);
		
		if(gpio_write_value(gpio, 0) != EXIT_SUCCESS){
			return EXIT_FAILURE;
		}
		usleep(delay_ms);
	}
	//unexport
	if(gpio_unexport(gpio) != EXIT_SUCCESS){
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
