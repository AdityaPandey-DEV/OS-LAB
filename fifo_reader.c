#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    const char *fifo = "/tmp/myfifo";
    mkfifo(fifo, 0666);
    char buf[256];
    int fd = open(fifo, O_RDONLY);
    if (fd == -1) return 1;
    int n = read(fd, buf, sizeof(buf) - 1);
    if (n > 0) {
        buf[n] = '\0';
        printf("Reader got: %s\n", buf);
    }
    close(fd);
    return 0;
}
