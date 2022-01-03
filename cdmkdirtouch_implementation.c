#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
	chdir(argv[1]);
	mkdir(argv[2], 0777);
	chdir(argv[2]);
	int fd = openat(AT_FDCWD, argv[3], O_WRONLY|O_CREAT, 0666);
	futimens(fd, NULL);
	close(fd);
}
