#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>

int main() {
	
	if(mkfifo("file1", 0777) == -1) {
		if(errno != EEXIST) {
			printf("Problem in creating fifo");
			return 1;
		}
	}
	
	printf("P1 : Writing Process Starts in file1\n");
	printf("P1 : file 1 is opening\n");
	int fd = open("file1", O_WRONLY);
	if(fd == -1) { 
		return 2;
	}
	
	printf("P1 : file 1 is opened\n");
	printf("P1 : Writng in file1\n");
	int i = 1;
	int x = i++;
	printf("\n");
	if (write(fd, &x, sizeof(x)) == -1) {
		return 3;
	}
	printf("P1 : %d Written in file1\n", x);
	
	close(fd);
	printf("P1 : fd is closed\n");



	printf("P1 : Reading Process starts from file2\n");
	printf("P1 : file 2 is opening\n");
	int fd = open("file2", O_RDONLY);
	if(fd == -1) { 
		return 2;
	}
	
	printf("P1 : file 2 is opened\n");
	printf("P1 : Reading from file2\n");
	int y;
	if (read(fd, &y, sizeof(y)) == -1) {
		return 3;
	}
	printf("P1 : %d Read from file2\n", y);
	
	close(fd);
	printf("P1 : fd is closed\n");


	
	return 0;
	//bhfbh
}