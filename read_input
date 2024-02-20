#include "shell.h"

/**
 * read_line - Creates a file.
 *
 * Return: If the function fails return Null
 */
char *read_line(void) 
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t chars_read = getline(&line, &bufsize, stdin);
    
    if (chars_read == -1)
    {
        free(line);
        if (feof(stdin))
        {
            exit(EXIT_SUCCESS);
        } else
        {
            perror("Error while reading the line from stdin");
            exit(EXIT_FAILURE);
        }
    } else if (chars_read == 0)
    {
        free(line);
        return (NULL);
    } else
    {
        return (line);
    }
}
