#include "shell.h"
/**
 * prompt - function that prints '$' to standard output
 * Return:no return value
 */
void prompt(void)
{
	PRINT("$ ");
}

/**
 * PRINT - To print the output
 * @message: A pointer for the output message
 * Return: noting
 */
void PRINT(const char *message)
{
    write(STDOUT_FILENO, message, strlen(message));
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * strlen - function that counts the length of a string
 * @s: string input
 * Return: length of string
 */
int strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}
