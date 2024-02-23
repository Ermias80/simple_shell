#include "shell.h"
/**
 * is_interactive - To check if it is running in interactive mode or not.
 * Return: true if it is interactive, false otherwise.
 */
bool is_interactive(void)
{
return (isatty(fileno(stdin)) != 0);
}
