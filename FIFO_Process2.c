#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>

int main() {
	
	
	
	printf("P2 : Reading Process starts from file1\n");
	printf("P2 : file 1 is opening\n");
	int fd = open("file1", O_RDONLY);
	if(fd == -1) { 
		return 2;
	}
	
	printf("P2 : file 1 is opened\n");
	printf("P2 : Reading from file1\n");
	int x;
	if (read(fd, &x, sizeof(x)) == -1) {
		return 3;
	}
	printf("P2 : %d Read from file1\n", x);
	
	close(fd);
	printf("P2 : fd is closed\n");



	if(mkfifo("file2", 0777) == -1) {
		if(errno != EEXIST) {
			printf("Problem in creating fifo");
			return 1;
		}
	}
	
	printf("P2 : Writing Process Starts in file2\n");
	printf("P2 : file 2 is opening\n");
	int fd = open("file2", O_WRONLY);
	if(fd == -1) { 
		return 2;
	}
	
	printf("P2 : file 2 is opened\n");
	printf("P2 : Writng in file2\n");
	int j = 1;
	int y = j++;
	printf("\n");
	if (write(fd, &y, sizeof(y)) == -1) {
		return 3;
	}
	printf("P2 : %d Written in file2\n", y);
	
	close(fd);
	printf("P2 : fd is closed\n");
	
	return 0;
}