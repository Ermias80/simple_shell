#include <shell.h>
/**
 * stringcpy - Copies a string from source to destination.
 * @destination: Pointer to the destination string.
 * @source: Pointer to the source string.
 * Return: Pointer to the destination string.
 */
char *stringcpy(char *destination, char *source)
{
	int index = 0;

	if (destination == source || source == NULL)
	{
		return (destination);
	}
	do {
		destination[index] = source[index];
		index++;
	} while (source[index - 1] != '\0');
	return (destination);
}

/**
 * string_dup - duplicates a string
 * @original: the string to duplicate
 * Return: pointer to the duplicated string
 */
char *string_dup(const char *original)
{
	int len = 0;
	char *result;

	if (original == NULL)
		return (NULL);
	const char *temp = original;

	while (*temp != '\0)
	{
		len++;
		temp++;
	}
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	int index = 0;
	while (original[index] != '\0')
	{
		result[index] = original[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}
