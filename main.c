
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
    char *line;
    fd = open("test.txt", O_RDWR);
    while (1)
    {
        line = get_next_line(fd);
        printf("%s", line);
        free(line);
        if (!line)
            break;
    }
}