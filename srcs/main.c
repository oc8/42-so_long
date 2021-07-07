#include "so_long.h"

static size_t	count_line(char *file, t_main *main)
{
	char 	*buf;
	size_t	count;
	int		rv;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		quit(strerror(errno), main);
	count = 0;
	rv = 1;
	while (rv && rv != -1)
	{
		// main->map[i] = ft_calloc_lst(&main->malloc, size[1], 1);
		rv = get_next_line(fd, &buf);
		free(buf);
		count++;
	}
	close(fd);
	if (rv == -1)
		quit(strerror(errno), main);
	return (count);
}

static void read_file(char *file, t_main *main)
{
	int		rv;
	int		fd;
	size_t	i;

	main->map.h = count_line(file, main);
	main->map.map = ft_calloc_lst(&main->malloc, main->map.h + 1, sizeof(char *)); // false num
	fd = open(file, O_RDONLY);
	if (fd == -1)
		quit(strerror(errno), main);
	rv = 1;
	i = 0;
	while (rv && rv != -1)
	{
		rv = get_next_line(fd, &main->map.map[i]);
		i++;
	}
	close(fd);
	if (rv == -1)
		quit(strerror(errno), main);
	main->map.w = ft_strlen(main->map.map[0]);
}

void	create_map(char *map, t_main *main)
{
	read_file(map, main);
	for (int i = 0; main->map.map[i]; i++)
		printf("%s\n", main->map.map[i]);
}

int	loop(t_main *main)
{
	edit_screen(main);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_main	main;

	if (argc != 2)
	{
		ft_putstr_fd("one arg is required\n", 2);
		return (1);
	}
	ft_bzero(&main, sizeof(t_main));
	pars_map(argv[1], &main);
	create_map(argv[1], &main);
	main.scr.w = 1000;
	main.scr.h = 1000;
	main.map.ratio_w = main.scr.w / main.map.w;
	main.map.ratio_h = main.scr.h / main.map.h;
	printf("%zu, %zu\n", main.map.ratio_w, main.map.ratio_h);
	mlx_loop_hook(main.mlx_ptr, loop, &main);
	mlx_loop(main.mlx_ptr);
	return (0);
}
