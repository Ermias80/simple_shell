#include "shell.h"
/**
 * custom_puts - prints an input string
 * @input_string: the string to be printed
 *
 * Return: Nothing
 */
void custom_puts(char *input_string)
{
	int index = 0;

	if (input_string == NULL)
		return;
	while (*(input_string + index))
	{
		_putcharacter(*(input_string + index));
		index++;
	}
}

/**
 * _putcharacter - Writes the specified character to standard output.
 * @character: The character to be written.
 *
 * Return: On success, returns 1.
 *         On error, returns -1 and sets errno appropriately.
 */

int _putcharacter(char character)
{
	static int index;
	static char buffer[WRITE_BUF_SIZE];

	switch (character)
	{
		case BUF_FLUSH:
			if (index >= WRITE_BUF_SIZE)
			{
				write(1, buffer, index);
				index = 0;
			}
			break;
		default:
			if (index >= WRITE_BUF_SIZE)
			{
				write(1, buffer, index);
				index = 0;
			}
			buffer[index++] = character;
			break;
	}
	return (1);
}
/**
 * string_length - returns the length of a string
 * @string: the string whose length to check
 *
 * Return: integer length of string
 */
int string_length(char *string)
{
	int length = 0;

	if (string == NULL)
		return (0);
	for (length = 0; string[length] != '\0'; length++)
		;
	return (length);
}

/**
 * string_compare - performs lexicographic comparison of two strings.
 * @str1: the first string
 * @str2: the second string
 *
 * Return: -ve if str1 < str2, +ve if str1 > str2, 0 if str1 == str2
 */
int string_compare(char *str1, char *str2)
{
	for (; *str1 && *str2; str1++, str2++)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}
/**
 * string_starts_with - checks if the 'needle' string starts with 'haystack'.
 * @haystack: the string to search
 * @needle: the substring to find
 *
 * Return: addrs of next chr of 'haystack' if 'needle'start wz 'haystack',NULL
 */
char *string_starts_with(const char *haystack, const char *needle)
{
	const char *h = haystack;
	const char *n = needle;

	if (*needle == '\0')
		return ((char *)haystack);
	do {
		if (*h != *n)
			return (NULL);
		h++;
		n++;
	} while (*n != '\0');
	return ((char *)haystack);
}
