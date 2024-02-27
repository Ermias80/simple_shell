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
#include <stddef.h>

char *read_line(void);
void prompt(void);
void PRINT(const char *message);
size_t strlen(const char *s);

/**Toknizeers*/
static int count_words(const char *string, const char *delimiters);
static char *allocate_and_copy_word(const char *src, int start, int end);
char **stringToArray(const char *string, const char *delimiters);
int is_delim(char c, const char *delimiters);
char **stringToWo(char *string, char d);
int countWords(char *string, char d);
char **splitIntoWords(char *string, char d, int numWords);

/* path finder */
int is_exet_cmd(info_t *info, char *path);
char *duplicate_chars(char *pathstr, int start, int stop);
char *find_command_path(info_t *info, char *path_string, char *command);

#endif
