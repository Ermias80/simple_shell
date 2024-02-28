#include "shell.h"
/**
 * list_length - Counts the number of nodes in a linked list.
 * @head: Pointer to the first node.
 *
 * Return: The number of nodes in the list.
 */
size_t list_length(const list_t *head)
{
	size_t count = 0;

	for (; head != NULL; head = head->next)
	{
		count++;
	}
	return (count);
}

/**
 * list_to_strings - Converts linked list nodes to an array of strings.
 * @head: Pointer to the first node.
 *
 * Return: Array of strings.
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t count = list_length(head), i, j;
	char **strs;
	char *str;

	if (head == NULL || count == 0)
		return (NULL);
	strs = malloc(sizeof(char *) * (count + 1));
	if (strs == NULL)
		return (NULL);
	i = 0;
	while (node != NULL)
	{
		str = malloc(string_length(node->str) + 1);
		if (str == NULL)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
		str = stringcpy(str, node->str);
		strs[i] = str;
		i++;
		node = node->next;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * print_list - Prints all elements of a list_t linked list.
 * @h: Pointer to the first node.
 *
 * Return: Number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
	size_t count;

	for (count = 0; h != NULL; h = h->next)
	{
		custom_puts(convert_number(h->num, 10, 0));
		_putcharacter(':');
		_putcharacter(' ');
		custom_puts(h->str ? h->str : "(nil)");
		custom_puts("\n");
		count++;
	}
	return (count);
}
