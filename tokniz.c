#include "shell.h"

/**
 * count_words - counts the number of words in a string
 * @string: the input string
 * @delimiters: the delimiter string
 * Return: the number of words
 */
static int count_words(const char *string, const char *delimiters)
{
	int num_words = 0;
	int i = 0;

	while (string[i] != '\0')
	{
		if (!is_delim(string[i], delimiters))
		{
			num_words++;
			while (string[i] != '\0' && !is_delim(string[i], delimiters))
				i++;
		}
		else
		{
			i++;
		}
	}
	return (num_words);
}

/**
 * is_delim - checks if a character is a delimiter
 * @c: the character to check
 * @delimiters: the string containing delimiter characters
 * Return: 1 if c is a delimiter, 0 otherwise
 */
int is_delim(char c, const char *delimiters)
{
	while (*delimiters != '\0')
	{
		if (c == *delimiters)
			return (1);
		delimiters++;
	}
	return (0);
}

/**
 * allocate_and_copy_word - allocates memory for a word and copies it
 * @src: the source string
 * @start: the starting index of the word
 * @end: the ending index of the word
 * Return: a pointer to the allocated and copied word
 */
static char *allocate_and_copy_word(const char *src, int start, int end)
{
	int length = end - start;
	char *word = malloc((length + 1) * sizeof(char));

	if (!word)
		return (NULL);
	for (int i = 0; i < length; i++)
	{
		word[i] = src[start + i];
	}
	word[length] = '\0';
	return (word);
}

/**
 * stringToArray - breaks  string to words. Consecutive delimiters are ignored
 * @s: the input string
 * @d: the delimiter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **stringToArray(const char *s, const char *d)
{
	int num_words = 0;
	int w_index = 0;
	int str_index = 0;
	int word_s = 0;
	int word_e = 0;
	char **result = NULL;

	if (!s || *s == '\0')
		return (NULL);
	if (!d)
		d = " ";
	num_words = count_words(s, d);
	if (num_words == 0)
		return (NULL);
	result = malloc((num_words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (w_index < num_words)
	{
		while (s[str_index] != '\0' && is_delim(s[str_index], d))
			str_index++;
		word_s = str_index;
		while (s[str_index] != '\0' && !is_delim(s[str_index], d))
		{
			str_index++;
			word_e = str_index;
		}
		result[w_index] = allocate_and_copy_word(s, word_s, word_e);
		if (!result[w_index])
		{
			for (int i = 0; i < w_index; i++)
				free(result[i]);
			free(result);
			return (NULL);
		}
		w_index++;
	}
	result[num_words] = NULL;
	return (result);
}

/**
 * **stringToWo - splits a string into words
 * @string: the input string
 * @d: the delimiter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **stringToWo(char *string, char d)
{
	if (string == NULL || string[0] == '\0')
		return (NULL);
	int numWords = countWords(string, d);

	if (numWords == 0)
		return (NULL);
	return (splitIntoWords(string, d, numWords));
}
