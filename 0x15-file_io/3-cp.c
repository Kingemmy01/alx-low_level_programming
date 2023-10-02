#include "main.h"

char *creat_buffer(char *file);
void close_file(int fd);

/**
 * creat_buffer - allocates 1024 bytes to a buffer
 * @file: the name of file to store buffer chars
 *
 * Return: a pointer to the aloocated buffer
 */
char *creat_buffer(char *file)
{

	char *buffer = (char *)malloc(1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - closes the file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int cl;

	cl = close(fd);

	if (cl == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the contents of a file to another file.
 * @argc: The number of arguments supplied
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success or otherwise
 *
 * Description: If the count of argument is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to failed or cannot be created - exit code 99.
 * If file descriptor cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	char *buffer;
	int from, to, rd, wt;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = creat_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	rd = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || rd == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}
		wt = write(to, buffer, rd);
		if (to == -1 || wt == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		rd = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (rd > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
