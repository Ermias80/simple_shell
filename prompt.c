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
size_t strlen(const char *s)
{
    size_t i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}
