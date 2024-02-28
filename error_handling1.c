#include "shell.h"
/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = (flags & CONVERT_LOWERCASE) ? "0123456789abcd" : "0123456789ABCD";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_decimal - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_decimal(int input, int fd)
{
	int (*__putcharacter)(char) = _putcharacter;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putcharacter = errputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putcharacter('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	while (i > 1)
	{
		i /= 10;
		if (_abs_ / i)
		{
			__putcharacter('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putcharacter('0' + current);
	count++;
	return (count);
}

/**
 * errprt - prints an input string to stderr
 * @s: the string to be printed
 *
 * Return: Nothing
 */
void errprt(char *s)
{
	if (!s)
		return;
	for (int i = 0; s[i] != '\0'; i++)
	{
		errputchar(s[i]);
	}
}

/**
 * error_print - prints an error message to stderr
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 *
 * Return: void
 */
void error_print(info_t *info, char *estr)
{
	errprt(info->fname);
	errprt(": ");
	print_decimal(info->line_count, STDERR_FILENO);
	errprt(": ");
	errprt(info->argv[0]);
	errprt(": ");
	errprt(estr);
}
