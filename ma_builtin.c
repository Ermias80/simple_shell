#include "shell.h"

/**
 * ma_cd - Change the current directory
 * @dir: Directory containing the path to the destination working directory
 * Return: Path to destination directory
 */
void ma_cd(char *dir)
{
	char *cwd = NULL, *home = NULL, *prev_dir = NULL, *old_dir = getcwd(NULL, 0);

	if (old_dir == NULL)
		return;

	track_address(old_dir);
	if (dir == NULL || ma_strcmp(dir, "") == 0)
	{
		home = ma_getenv("HOME");
		if (home == NULL)
		{
			return;
		}
		track_address(home);
		if (chdir(home) != 0)
		{
			ma_perror_cd(dir, 2);
			free(old_dir);
			free(home);
			return;
		}
		cwd = getcwd(NULL, 0);
		track_address(cwd);
	}
	else if (ma_strcmp(dir, "-") == 0)
	{
		prev_dir = ma_getenv("OLDPWD");
		if (prev_dir == NULL)
		{
			return;
		}
		track_address(prev_dir);
		if (chdir(prev_dir) != 0)
		{
			ma_perror_cd(dir, 2);
			free(prev_dir);
			return;
		}
		cwd = getcwd(NULL, 0);
		if (cwd)
			track_address(cwd);

		write(1, cwd, ma_strlen(cwd));
		write(1, "\n", 1);
	}
	else
	{
		if (chdir(dir) != 0)
		{
			ma_perror_cd(dir, 2);
			return;
		}
		cwd = getcwd(NULL, 0);
		track_address(cwd);
	}
	ma_setenv("PWD", cwd);
	ma_setenv("OLDPWD", old_dir);
}

/**
 * exit_shell - Exit the shell with a given status
 * @argv: Array of arguments passed to the program
 * Return: 2 on failure
 */
int exit_shell(char **argv)
{
	int status;

	if (argv[1] == NULL)
	{
		sweep_all(argv);
		exit(exit_status);
	}
	else
	{
		status = ma_atoi(argv[1]);
		if ((status == 0) && (ma_strcmp(argv[1], "0") == 0))
		{
			sweep_all(argv);
			exit(status);
		}
		else if (status > 0)
		{
			sweep_all(argv);
			exit(status);
		}
		else if (status < 1)
		{
			display_errorexit(argv[1]);
		}
	}
	return (2);
}
