#include <elf.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - checks whether a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic nums.
 *
 * Description: If the file is not an ELF file -
 * exit with status code 98.
 * and display a comprehensive error message to stderr
 */
void check_elf(unsigned char *e_ident)
{
	int count;

	for (count = 0; count < 4; count++)
	{
		if (e_ident[count] != 127 &&
		    e_ident[count] != 'E' &&
		    e_ident[count] != 'L' &&
		    e_ident[count] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);

		}
	}
}

/**
 * print_magic - prints the magic numbs of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbs.
 *
 * Description: Magic nums are separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
	int count;

	printf(" Magic: ");

	for (count = 0; count < EI_NIDENT; count++)
	{
		printf("%02x", e_ident[count]);

		if (count == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_data - prints the data of an ELF header.
 * @e_ident: A pointer to an array containi the ELF class.
 */
void print_data(unsigned char *e_ident)
{
	printf(" Data: ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_class - prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *e_ident)
{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_abi - prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n",
		e_ident[EI_ABIVERSION]);
}
