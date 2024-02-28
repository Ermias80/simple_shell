#include "shell.h"
/**
 * err_str_toint - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int err_str_toint(char *str)
{
	unsigned long int result = 0;
	int digit_found = 0;

	if (*str == '+')
		str++;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			result *= 10;
			result += (*str - '0');
			digit_found = 1;
			if (result > INT_MAX)
				return (-1);
		}
		else if (digit_found)
		{
			return (-1);
		}
		else if (*str == '-')
		{
			if (*str == '\0')
				return (-1);
				str++;
			continue;
		}
		else
			return (-1);
		str++;
	}
	if (!digit_found)
		return (0);
	return (result);
}

/**
 * errputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int errputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	switch (c)
	{
		case BUF_FLUSH:
		case '\0':
			if (i > 0 && write(2, buf, i) == -1)
				return (-1);
			i = 0;
			break;
		default:
			if (i < WRITE_BUF_SIZE - 1)
				buf[i++] = c;
			else
			{
				if (write(2, buf, i) == -1)
					return (-1);
				i = 0;
				buf[i++] = c;
			}
			break;
	}
	return (1);
}

/**
 * put_to_fd - writes the character c to the given file descriptor
 * @c: The character to print
 * @fd: The file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int put_to_fd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	switch (c)
	{
		case BUF_FLUSH:
		case '\0':
			if (i > 0 && write(fd, buf, i) == -1)
				return (-1);
			i = 0;
			break;
		default:
			if (i < WRITE_BUF_SIZE - 1)
				buf[i++] = c;
			else
			{
				if (write(fd, buf, i) == -1)
					return (-1);
				i = 0;
				buf[i++] = c;
			}
			break;
	}
	return (1);
}

/**
 * puts_to_fd - prints an input string to the specified file descriptor
 * @str: the string to be printed
 * @fd: the file descriptor to write to
 *
 * Return: the number of characters printed
 */
int puts_to_fd(char *str, int fd)
{
	int char_count = 0;

	if (!str)
		return (0);
	do {
		if (put_to_fd(*str++, fd) == -1)
			return (-1);
		char_count++;
	} while (*(str - 1));
	return (char_count);
}


