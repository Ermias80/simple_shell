#include "shell.h"
/**
 * initialize_info - Initializes the info_t struct
 * @info: Pointer to the info_t struct
 */
void initialize_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}
/**
 * set_info - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */
void set_info(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];

	if (info->arg)
	{
		int num_words = count_words(info->arg, " \t");

		if (num_words > 0)
		{
			info->argv = stringToArray(info->arg, " \t");
			if (info->argv)
			{
				for (i = 0; info->argv[i]; i++)
					;
				info->argc = i;
			}
			else
			{
				info->argv = malloc(sizeof(char *) * 2);

				if (info->argv)
				{
info->argv[0] = allocate_and_copy_word(info->arg, 0, strlen(info->arg));
info->argv[1] = NULL;
info->argc = 1;
				}
			}
			if (info->argv)
			{
				replace_alias(info);
				replace_vars(info);
			}
		}
	}
}

