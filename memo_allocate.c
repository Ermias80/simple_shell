#include "shell.h"
/**
 * bfree_loop - frees a pointer and NULLs the address using a loop
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree_loop(void **ptr)
{
	switch (*ptr != NULL)
	{
		case 1:
			free(*ptr);
			*ptr = NULL;
			return (1);
		default:
			return (0);
	}
}

/**
 * memo - fills memory with a constant byte using a do-while loop
 * @ptr: the pointer to the memory area
 * @byte: the byte to fill *ptr with
 * @size: the amount of bytes to be filled
 * Return: a pointer to the memory area ptr
 */
char *memo(char *ptr, char byte, unsigned int size)
{
	unsigned int i = 0;

	if (size > 0)
	{
		do {
			ptr[i] = byte;
			i++;
		} while (i < size);
	}
	return (ptr);
}

/**
 * strings_free - frees a string of strings
 * @str_arr: string of strings
 */
void strings_free(char **str_arr)
{
	char **temp = str_arr;

	if (!str_arr)
		return;
	for (; *str_arr != NULL; str_arr++)
	{
		free(*str_arr);
	}
	free(temp);
}

/**
 * realloc_memo - reallocates a block of memory
 * @ptr: pointer to previously allocated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to the reallocated block.
 */
void *realloc_memo(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	unsigned int copy_size = old_size < new_size ? old_size : new_size;

	for (unsigned int i = 0; i < copy_size; i++)
		p[i] = ((char *)ptr)[i];
	free(ptr);
	return (p);
}
