#ifndef MAIN_H
#define MAIN_H

//#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))

/**Standard Library*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>

typedef struct passinfo {
    char *arg;
    char **argv;
    char *path;
    int argc;
    unsigned int line_count;
    int err_num;
    int linecount_flag;
    char *fname;
    list_t *env;
    list_t *history;
    list_t *alias;
    char **environ;
    int env_changed;
    int status;

    char **cmd_buf; /* Pointer to command buffer for chaining commands */
    int cmd_buf_type; /* Type of command buffer (e.g., ||, &&, ;) */
    int readfd; // File descriptor for reading input
    int histcount; // Count of history lines

} info_t;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct list_t
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}


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


/*for strings*/
char *stringcpy(char *destination, char *source);
char *string_dup(const char *original);
void custom_puts(char *input_string);
int _putcharacter(char character);
int string_length(char *string);
int string_compare(char *str1, char *str2);
char *string_starts_with(const char *haystack, const char *needle);
char *string_concat(char *destination, char *source);
char *custom_strncpy(char *destination, const char *source, int num);
char *concatenate_string(char *destination, const char *source, int num);
char *locate_chr_str(char *str, char chr);
bool starts_with(const char *str, const char *prefix);

/**  memory allocation */
void *realloc_memo(void *ptr, unsigned int old_size, unsigned int new_size);
void strings_free(char **str_arr);
char *memo(char *ptr, char byte, unsigned int size);
int bfree_loop(void **ptr);


#endif
