#include "shell.h"
/**
 * env1 - Prints the current environment.
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0.
 */
int env1(info_t *info)
{
	print_str_at_list(info->env);
	return (0);
}

/**
 * get_env_value - Retrieves the value of an environment variable.
 * @data: Pointer to a structure containing potential arguments.Used 2maintain
 *        context for the function.
 * @name: Name of the environment variable to retrieve.
 * Return:
 *   If the environment variable is found, returns a pointer to its value.
 */
char *get_env_value(info_t *data, const char *name)
{
	list_t *node = data->env;
	char *p;

	if (!node)
		return (NULL);
	do {
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	} while (node);
	return (NULL);
}

/**
 * set_enviro - Initialize a new environment variable or modify an existing 1
 * @data: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @property: The string representing the environment variable property.
 * @value: The string representing the environment variable value.
 *
 * Return: Always returns 0.
 */
int set_enviro(info_t *data, char *property, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!property || !value)
		return (0);
	buf = malloc(stringlen(property) + stringlen(value) + 2);
	if (!buf)
		return (1);
	stringcpy(buf, property);
	string_concat(buf, "=");
	string_concat(buf, value);
	node = data->env;
	if (!node)
	{
		Add_end_to_node(&(data->env), buf, 0);
		free(buf);
		data->env_changed = 1;
		return (0);
	}
	do {
		p = starts_with(node->str, property);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			data->env_changed = 1;
			return (0);
		}
		node = node->next;
	} while (node);
	Add_end_to_node(&(data->env), buf, 0);
	free(buf);
	data->env_changed = 1;
	return (0);
}
