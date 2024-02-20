#ifndef MAIN_H
#define MAIN_H

//#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))

/**Standard Library*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_line(void);
void prompt(void);
void PRINT(const char *message);
int strlen(char *s);

#endif
