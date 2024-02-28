#include "shell.h"
/**
 * string_concat - concatenates two strings
 * @destination: the destination buffer
 * @source: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *string_concat(char *destination, char *source)
{
	char *result = destination;

	do {
		destination++;
	} while (*destination);

	do {
		*destination++ = *source++;
	} while (*source);
	*destination = *source;
	return (result);
}
/**
 * custom_strncpy - copies a string up to num characters
 * @destination: the destination string to be copied to
 * @source: the source string
 * @num: the maximum number of characters to be copied
 * Return: a pointer to the destination string
 */
char *custom_strncpy(char *destination, const char *source, int num)
{
	int i;

	for (i = 0; i < num && source[i] != '\0'; i++)
	{
		destination[i] = source[i];
	}
	for (; i < num; i++)
	{
		destination[i] = '\0';
	}
	return (destination);
}

/**
 * *concatenate_string - appends a portion of one string to another
 * @destination: pointer to the destination string
 * @source: pointer to the source string
 * @num: the maximum number of characters to append
 * Return: pointer to the resulting string
 */
char *concatenate_string(char *destination, const char *source, int num)
{
	int x, y;
	char *result = destination;

	for (x = 0; destination[x] != '\0'; x++)
		;
	for (y = 0; source[y] != '\0' && y < num; y++)
	{
		destination[x + y] = source[y];
	}
	if (y < num)
	{
		destination[x + y] = '\0';
	}
	return (result);
}

/**
 * locate_chr_str - Locates a specific character in a given string.
 * @str: The string to be searched.
 * @chr: The character to search for.
 *
 * Return: A pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
char *locate_chr_str(char *str, char chr)
{
	for (; *str != '\0'; str++)
	{
		if (*str == chr)
			return (str);
	}
	return (NULL);
}
