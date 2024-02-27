#include "shell.h"
/**
 * is_exet_cmd - determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_exet_cmd(info_t *info, char *path)
{
	struct stat st;
	(void)info;
	if (!path || stat(path, &st) != 0)
		return (0);
	if (access(path, X_OK) == 0)
	{
		return (1);
	}
	return (0);
}

/**
 * duplicate_characters - duplicates characters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *duplicate_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int j = start, m = 0;

	do {
		if (pathstr[j] != ':')
			buf[m++] = pathstr[j];
		j++;
	} while (j < stop);
	buf[m] = '\0';
	return (buf);
}

/**
 * find_command_path - locates the specified command wz PATH environment var
 * @info: the info struct
 * @path_string: the PATH environment variable string
 * @command: the command to locate
 *
 * Return: the full path of the command if found, or NULL if not found
 */
char *find_command_path(info_t *info, char *path_string, char *command)
{
	int index = 0, curr_pos = 0;
	char *path;

	if (!path_string)
		return (NULL);
	if ((string_length(command) > 2) && starts_with(command, "./"))
	{
		if (is_exet_cmd(info, command))
			return (command);
	}
	do {
		if (!path_string[index] || path_string[index] == ':')
		{
			path = duplicate_chars(path_string, curr_pos, index);
			if (!*path)
				string_concat(path, command);
			else
			{
				string_concat(path, "/");
				string_concat(path, command);
			}
			if (is_exet_cmd(info, path))
				return (path);
			if (!path_string[index])
				break;
			curr_pos = index;
		}
		index++;
	} while (1);
	return (NULL);
}
