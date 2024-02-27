#include "shell.h"
/**
 * countWords - counts the number of words in a string
 * @string: the input string
 * @d: the delimiter
 * Return: the number of words
 */
int countWords(char *string, char d)
{
	int numWords = 0;
	int a = 0;

	while (string[a] != '\0')
	{
	if (string[a] != d && (string[a + 1] == d || string[a + 1] == '\0'))
		numWords++;
	a++;
	}
	return (numWords);
}

/**
 * splitIntoWords - splits a string into words
 * @string: the input string
 * @d: the delimiter
 * @numWords: the number of words
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **splitIntoWords(char *string, char d, int numWords)
{
	char **s = malloc((numWords + 1) * sizeof(char *));

	if (!s)
		return (NULL);
	int a = 0, b = 0;

	while (b < numWords)
	{
		while (string[a] == d && string[a] != '\0')
			a++;
		int c = 0;

		while (string[a + c] != d && string[a + c] != '\0')
			c++;
		s[b] = malloc((c + 1) * sizeof(char));
		if (!s[b])
		{
			for (int i = 0; i < b; i++)
				free(s[i]);
			free(s);
			return (NULL);
		}
		for (int i = 0; i < c; i++)
			s[b][i] = string[a++];
		s[b][c] = '\0';
		b++;
	}
	s[b] = NULL;
	return (s);
}
