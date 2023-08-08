#include "main.h"

/**
 * read_textfile- reads a text file print to STDOUT.
 * @filename: text file to be read
 * @letters: number of letters to be read and printed
 * Return: wt- actual number of bytes read and printed
 *        0 when filename is NULL or function fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t rd;
	ssize_t wt;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	rd = read(fd, buf, letters);
	wt = write(STDOUT_FILENO, buf, rd);

	free(buf);
	close(fd);
	return (wt);
}
