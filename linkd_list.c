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
	const list_t *current = head;

	if (current == NULL)
		return (count);
	do {
		count++;
		current = (const list_t *)current->next;
	} while (current != NULL);
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
	size_t count = list_length(head), i;
	char **strs;

	if (head == NULL || count == 0)
		return (NULL);
	strs = malloc(sizeof(char *) * (count + 1));
	if (strs == NULL)
		return (NULL);
	i = 0;
	while (node != NULL)
	{
		strs[i] = malloc(string_length(node->str) + 1);
		if (strs[i] == NULL)
		{
			for (size_t j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
		stringcpy(strs[i], node->str);
		i++;
		node = (list_t *)node->next;
	}
	strs[i] = NULL;
	return strs;
}


/**
 * list_p - prints all elements of a list_t linked list
 * @head: pointer to first node
 *
 * Return: size of list
 */
size_t list_p(const list_t *head)
{
	size_t i;
	const list_t *current = head;

	for (i = 0; current; i++)
	{
		custom_puts(convert_number(current->num, 10, 0));
		_putcharacter(':');
		_putcharacter(' ');
		custom_puts(current->str ? current->str : "(nil)");
		custom_puts("\n");
		current = (const list_t *)current->next;
	}
	return (i);
}

/**
 * nod_wz_starts - returns node whose string starts with prefix
 * @nd: pointer to list head
 * @prfx: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *nod_wz_starts(list_t *nd, char *prfx, char c)
{
	char *p = NULL;

	if (!nd)
		return (NULL);
	do {
		p = string_starts_with(nd->str, prfx);
		if (p && ((c == -1) || (*p == c)))
			return (nd);
		nd = (list_t *)nd->next;
	} while (nd);
	return (NULL);
}
/**
 * getnd_indx - Retrieves the index of a given node within a linked list.
 * @hd: Pointer to the head of the linked list.
 * @nd: Pointer to the node to search for.
 *
 * Return: Index of the node if found, otherwise -1.
 */
ssize_t getnd_indx(list_t *hd, list_t *nd)
{
	size_t idx = 0;

	if (!hd)
		return (-1);
	do {
		if (hd == nd)
			return (idx);
		hd = (list_t *)hd->next;
		idx++;
	} while (hd);
	return (-1);
}
