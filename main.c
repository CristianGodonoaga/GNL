#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int			get_next_line(int const fd, char **line);

int main()
{
    int fd;
    char *line;

    fd = open("C:\\Users\\Cristian "
					  "Godonoaga\\OneDrive\\Documenti\\Programming "
					  "Project\\get_next_line\\test.txt", O_WRONLY);
	write(fd, "test line oane\ntest line two", 29);
	close(fd);
	fd = open("C:\\Users\\Cristian "
					  "Godonoaga\\OneDrive\\Documenti\\Programming "
					  "Project\\get_next_line\\test.txt", O_RDONLY);
	write(fd, "test line oane\ntest line two", 29);
    get_next_line(fd, &line);
	close(fd);

    printf("\n%s", line);

    return 0;
}