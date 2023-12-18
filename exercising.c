#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>



char	*str_init(char *line)
{
	line = (char *)malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	return (line);
}

char	*extract_the_line(char *newbuffer, char *buffer, char **line)
{
	
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[42];

	line = NULL;
	line = str_init(line);
	if (fd < 0 || extract_the_line(buffer, &buffer[there_is_a_line(buffer)], &line) == NULL)
		return (NULL);
	
	return (line);
}

int main(int ac, char **av)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(av[1], O_RDONLY);
	line = NULL;

	if (ac == 2)
	{
		i = 1;
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("ligne %d --: %s\n", i, line);
			i++;
		}

	}
	free(line);
	printf("ligne --: (null)");
	return (0);
}