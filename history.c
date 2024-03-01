#include "shell.h"
/**
 * generate_history_file_path - generates the path for the history file
 * @info: parameter struct
 *
 * Return: allocated string containing history file path
 */
char *generate_history_file_path(info_t *info)
{
	char *path, *hm_d;
	hm_d = get_env_value(info, "HOME=");

	if (!hm_d)
		return (NULL);
	size_t path_length = string_length(hm_d) + string_length(HIST_FILE) + 2;
	path = malloc(sizeof(char) * path_length);
	if (!path)
		return (NULL);
	path[0] = '\0';
	stringcpy(path, hm_d);
	stringcpy(path, "/");
	string_concat(path, HIST_FILE);
	return (path);
}

/**
 * save_history_to_file - creates or appends to a file with history data
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int save_history_to_file(info_t *info)
{
	ssize_t file_descriptor;
	char *file_path = generate_history_file_path(info);
	list_t *current_node = info->history;

	if (!file_path)
		return (-1);
	file_descriptor = open(file_path, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(file_path);
	if (file_descriptor == -1)
		return (-1);
	while (current_node != NULL)
	{
		puts_to_fd(current_node->str, file_descriptor);
		put_to_fd('\n', file_descriptor);
		current_node = current_node->next;
	}
	put_to_fd(BUF_FLUSH, file_descriptor);
	close(file_descriptor);
	return (1);
}
/**
 * add_history_entry - Adds an entry to the history linked list
 * @info: Pointer to the parameter struct containing potential arguments.
 * @buffer: Pointer to the buffer containing the history entry to be added.
 * @line_count: The current line count of the history.
 *
 * Return: Always returns 0
 */
int add_history_entry(info_t *info, char *buffer, int line_count)
{
	list_t *new_node = NULL;
	switch (info->history != NULL)
	{
		case 1:
			new_node = info->history;
			break;
		default:
			break;
	}
	Add_end_to_node(&new_node, buffer, line_count);
	if (!info->history)
		info->history = new_node;
	return (0);
}

/**
 * history_numbers - Renumber the history linked list
 * @info: Pointer to the parameter struct containing potential arguments.
 *
 * This function iterates over the history linked list and updates the 'num'
 * field of each node to reflect its position in the list. It returns the new
 * histcount.
 *
 * Return: The new histcount
 */
int history_numbers(info_t *info)
{
	list_t *current_node = info->history;
	int count = 0;

	switch (current_node != NULL)
	{
		case 1:
			do {
				current_node->num = count++;
				current_node = current_node->next;
			} while (current_node != NULL);
			break;
		default;
		break;
	}
	return (info->histcount = count);
}

/**
 * read_history - Reads history from file
 * @info: The parameter struct
 *
 * This function reads history from a file, populates the history linked list
 * and returns the histcount on success, or 0 otherwise.
 *
 * Return: The histcount on success, 0 otherwise
 */
int read_history(info_t *info)
{
	ssize_t fd, rdlen;
	struct stat st;
	char *buf = NULL, *filename = generate_history_file_path(info);
	int linecount = 0;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
	{
		off_t fsize = st.st_size;
		switch (fsize < 2)
		{
			case 1:
				close(fd);
				return (0);
			default:
				break;
		}
		buf = malloc(sizeof(char) * (fsize + 1));
		if (!buf)
		{
			close(fd);
			return (0);
		}
		rdlen = read(fd, buf, fsize);
		buf[fsize] = '\0';
		switch (rdlen <= 0)
		{
			case 1:
				free(buf);
				close(fd);
				return (0);
			default:
				break;
		}
		close(fd);
		int i = 0, last = 0;
		while (i < fsize)
		{
			switch (buf[i] == '\n')
			{
				case 1:
					buf[i] = '\0';
					add_history_entry(info, buf + last, linecount++);
					last = i + 1;
					break;
				default:
					break;
			}
			i++
		}
		if (last != fsize)
		{
			add_history_entry(info, buf + last, linecount++);
		}
		free(buf);
		info->histcount = linecount;
		while (info->histcount-- >= HIST_MAX)
		{
			delete_node(&(info->history), 0)
		}
		rhistory(info);
		return (info->histcount);
	}
	return (0);
}

