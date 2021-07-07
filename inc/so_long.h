#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>

typedef struct	s_img
{
	void			*ptr;
	unsigned int	*pixels;
	size_t			w;
	size_t			h;
	int				bpp;
	int				s_l;
	int				endian;
}				t_img;

typedef struct	s_map
{
	char	**map;
	size_t	h;
	size_t	w;
	size_t	ratio_w;
	size_t	ratio_h;
}				t_map;

typedef struct s_main
{
	t_map	map;
	t_list	*malloc;
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	scr;
	t_img	floor;
	t_img	wall;
}				t_main;

void	pars_map(char *map, t_main *main);


void	my_mlx_init(t_main *main);
void	edit_screen(t_main *main);


void	quit(char *error, t_main *main);
int		print_error(char *error);

#endif
