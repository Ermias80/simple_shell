#include "shell.h"
/**
 * is_interactive - To chake it is running in interactive mode or
 * Return: true if it is interactive
 */
bool is_interactive(void)
{
return isatty(fileno(stdin)) != 0;
}