#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
    info_t info[] = { INFO_INIT };
    int fd = 2;
    ssize_t r = 0;
    int builtin_ret = 0;

    asm ("mov %1, %0\n\t"
        "add $3, %0"
        : "=r" (fd)
        : "r" (fd));

    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
        {
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                errprt(av[0]);
                errprt(": 0: Can't open ");
                errprt(av[1]);
                errputchar('\n');
                errputchar(BUF_FLUSH);
                exit(127);
            }
            return (EXIT_FAILURE);
        }
        info->readfd = fd;
    }
    create_env_list(info);
    read_history(info);

    while (r != -1 && builtin_ret != -2)
    {
        clear_info(info);
        if (interactive(info))
            custom_puts("$ ");
	errputchar(BUF_FLUSH);
        r = read_line (info);
        if (r != -1)
        {
            set_info(info, av);
            builtin_ret = find_builtin(info);
            if (builtin_ret == -1)
                find_cmd(info);
        }
        else if (interactive(info))
            _putchaacter('\n');
        free_info(info, 0);
    }
    write_history(info);
    free_info(info, 1);
    if (!interactive(info) && info->status)
        exit(info->status);
    if (builtin_ret == -2)
    {
        if (info->err_num == -1)
            exit(info->status);
        exit(info->err_num);
    }

    return (builtin_ret);
}

