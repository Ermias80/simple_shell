#ifndef MAIN_H
#define MAIN_H


/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_UNSIGNED 0x0001
#define CONVERT_LOWERCASE 2

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
    int readfd;
    int histcount;

} info_t;


#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}
/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

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

/**  List */
size_t list_p(const list_t *head);
char **list_to_strings(list_t *head);
size_t list_length(const list_t *head);
list_t *nod_wz_starts(list_t *nd, char *prfx, char c);
ssize_t getnd_indx(list_t *hd, list_t *nd);
list_t *AddNod(list_t **hd, const char *s, int num);
list_t *Add_end_to_node(list_t **hd, const char *s, int num);
size_t print_str_at_list(const list_t *node);
void free_nodes(list_t **head_ptr);

/** ERROR  */
int err_str_toint(char *str);
int errputchar(char c);
int put_to_fd(char c, int fd);
int puts_to_fd(char *str, int fd);
void rm_commt(char *b);
char *convert_number(long int num, int base, int flags);
int print_decimal(int input, int fd);
void errprt(char *s);
void error_print(info_t *info, char *estr);



#endif
