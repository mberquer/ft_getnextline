#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int			main()
{
    int		fd;
    char	*line;

    fd = open("test.txt", O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        printf("%s",line);
        line = get_next_line(fd);
    }
    close(fd);
}