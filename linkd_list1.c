#include "shell.h"
/**
 * AddNod - Adds a node to the beginning of the list.
 * @hd: Address of pointer to head node.
 * @s: String field of the node.
 * @num: Node index used by history.
 *
 * Return: Pointer to the newly added node, or NULL if memory allocation fails
 */
list_t *AddNod(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	memo((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}
/**
 * Add_end_to_node - Adds a node to the end of the list.
 * @hd: Address of pointer to head node.
 * @s: String field of the node.
 * @num: Node index used by history.
 *
 * Return: Pointer to the newly added node, or NULL if memory allocation fails.
 */
list_t *Add_end_to_node(list_t **hd, const char *s, int num)
{
	list_t *new_node, *node;

	if (!hd)
		return (NULL);
	node = *hd;
	new_node = memo(sizeof(list_t));
	if (!new_node)
		return (NULL);
	memo((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (s)
	{
		new_node->str = string_dup(s);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		for (; node->next; node = node->next)
			;
		node->next = new_node;
	}
	else
	{
		*hd = new_node;
	}
	return (new_node);
}

/**
 * print_str_at_list - prints the str element of each node in a list_t linked
 * @node: pointer to the first node
 *
 * Return: the number of nodes in the list
 */
size_t print_str_at_list(const list_t *node)
{
	size_t i = 0;

	if (!node)
		return (0);
	do {
		custom_puts(node->str ? node->str : "(nil)");
		custom_puts("\n");
		node = node->next;
		i++;
	} while (node);
	return (i);
}

/**
 * free_nodes - Frees all nodes of a list.
 * @head_ptr: Address of pointer to the head node.
 */
void free_nodes(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	switch (head_ptr != NULL && *head_ptr != NULL)
	{
		case 0:
			return;
		default:
			break;
	}
	head = *head_ptr;
	node = head;
	do {
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	} while (node);
	*head_ptr = NULL;
}

/**
 * delete_node - Deletes node at the given index.
 * @ptr: Address of pointer to the first node.
 * @index: Index of node to delete.
 *
 * Return: 1 on success, 0 on failure.
 */
int delete_node(list_t **ptr, unsigned int index)
{
    list_t *node, *prev_node;
    unsigned int i = 0;

    if (!ptr || !*ptr)
        return 0;

    if (index == 0)
    {
        node = *ptr;
        *ptr = (*ptr)->next;
        free(node->str);
        free(node);
        return 1;
    }

    prev_node = NULL;
    node = *ptr;
    do {
        if (i == index)
        {
            if (prev_node)
                prev_node->next = node->next;
            else
                *ptr = node->next;
            free(node->str);
            free(node);
            return 1;
        }
        prev_node = node;
        node = node->next;
        i++;
    } while (node);
    return 0;
}
