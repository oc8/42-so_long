#include "so_long.h"

static t_img	init_img(char *path, t_main *main)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(main->mlx_ptr, path, &img.w, &img.h);
	if (!img.ptr)
		quit("mlx_xpm_file_to_image() error", main);
	img.pixels = (unsigned int *)mlx_get_data_addr(img.ptr, &img.bpp, \
		&img.s_l, &img.endian);
	if (!img.pixels)
		quit("mlx_get_data_addr() error", main);
	ft_add_to_lst(main, img.ptr);
	return (img);
}

void	my_mlx_init(t_main *main)
{
	main->mlx_ptr = mlx_init();
	if (!main->mlx_ptr)
		quit("mlx_init() error", &main);
	main->mlx_win = mlx_new_window(main->mlx_ptr, main->scr.w, \
		main->scr.h, "so_long");
	if (!main->mlx_win)
		quit("mlx_new_window() error", &main);
	// ft_add_to_lst(cub, main->scr.ptr);
	main->scr.ptr = mlx_new_image(main->mlx_ptr, main->scr.w, main->scr.h);
	main->scr.pixels = (unsigned int *)mlx_get_data_addr(main->scr.ptr, \
		&main->scr.bpp, &main->scr.s_l, &main->scr.endian);
	if (!main->scr.pixels)
		quit("mlx_get_data_addr() error", &main);
	main->floor = init_img("assets/xpm/floor_1.xpm", main);
}