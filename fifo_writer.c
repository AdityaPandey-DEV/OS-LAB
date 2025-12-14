#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    const char *fifo = "/tmp/myfifo";
    mkfifo(fifo, 0666);
    const char *message = "Hello from writer process!";
    int fd = open(fifo, O_WRONLY);
    if (fd == -1) return 1;
    write(fd, message, strlen(message));
    close(fd);
    return 0;
}
