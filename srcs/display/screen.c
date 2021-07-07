#include "so_long.h"

static char	which_case(size_t h, size_t w, t_main *main)
{
	return (main->map.map[h][w]);
}

unsigned int which_pixel(size_t h, size_t w, char casee, t_main *main)
{
	h = h * 
}

static void	put_pixel(t_main *main)
{
	size_t	h;
	size_t	w;
	char	casee;
	unsigned int	color;

	h = 0;
	while (h < main->scr.h)
	{
		w = 0;
		while (w < main->scr.w)
		{
			casee = which_case(h / main->map.ratio_h, w / main->map.ratio_w, main);
			color = which_pixel(h % main->map.ratio_h, w % main->map.ratio_w, casee, main);
			if (casee == '1')
				main->scr.pixels[h * (main->scr.s_l / 4) + w] = 0xffffff;
			else
				main->scr.pixels[h * (main->scr.s_l / 4) + w] = color;
			w++;
		}
		h++;
	}
}

void	edit_screen(t_main *main)
{
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, main->mlx_win);
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, main->scr.ptr);
	put_pixel(main);
	mlx_put_image_to_window(main->mlx_ptr, main->mlx_win, main->scr.ptr, 0, 0);
	mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, main->mlx_win);
}