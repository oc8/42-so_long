#include "so_long.h"

int	print_error(char *error)
{
	ft_putstr_fd("\033[31m", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\033[0m\n", 2);
	return (1);
}

static void	free_all(t_main *main)
{
	ft_lstiter(main->malloc, free);
	ft_lstclear(&main->malloc, free);
}

void	quit(char *error, t_main *main)
{
	if (error)
		print_error(error);
	free_all(main);
	if (error)
		exit(1);
	exit(0);
}
