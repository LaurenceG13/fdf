/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.ch                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 13:50:23 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/21 13:21:48 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init_struct2(t_param *s)
{
	s->mlx = NULL;
	s->win = NULL;
	s->img = NULL;
	s->x_a = 0;
	s->x_b = 0;
	s->y_a = 0;
	s->y_b = 0;
	s->dx = 0;
	s->dy = 0;
	s->sx = 0;
	s->sy = 0;
	s->e = 0;
	s->e2 = 0;
	s->x_win = 0;
	s->y_win = 0;
	s->color = 0;
	s->color_name = NULL;
	s->tab = NULL;
	s->map = NULL;
	s->nb_lines = 0;
	s->nb_columns = 0;
	s->dest = NULL;
	s->scale = 0;
	s->dim_l = 0;
	s->dim_c = 0;
}

void	ft_init_struct1(t_param *s)
{
	s->x = 0;
	s->y = 0;
	s->x2 = 0;
	s->y2 = 0;
	s->perspective = 0;
	s->str_img = NULL;
	s->bpp = 0;
	s->s_l = 0;
	s->endian = 0;
	s->min_z = 0;
	s->max_z = 0;
	s->z2 = 0;
	s->z_a = 0;
	s->z_b = 0;
	s->x_slide = 0;
	s->y_slide = 0;
	s->deep = 0;
	s->putimg = 0;
	s->zoom = 0;
	s->high = 1;
	s->key = 0;
	s->nbcol_first = -1;
}

int		ft_usage(void)
{
	ft_putendl("usage : ./fdf file.fdf");
	return (0);
}

int		ft_error_malloc_struct(void)
{
	ft_putendl("Error : malloc struc didn't work");
	return (0);
}

int		main(int argc, char **argv)
{
	t_param	*s;
	int		fd;

	if (argc != 2)
		return (ft_usage());
	if ((fd = open(argv[1], O_DIRECTORY)) == -1)
	{
		if (!(s = (t_param *)ft_memalloc(sizeof(t_param))))
			return (ft_error_malloc_struct());
		ft_init_struct1(s);
		ft_init_struct2(s);
		if (ft_count_lines(argv[1], s) == -1)
			return (0);
		if (ft_split(argv[1], s) == -1)
			return (0);
		ft_size_win(s);
		s->mlx = mlx_init();
		s->win = mlx_new_window(s->mlx, s->x_win, s->y_win, "FdF");
		ft_trace_touching_points(s);
		mlx_hook(s->win, 2, 2, ft_keycode, s);
		mlx_loop(s->mlx);
	}
	else
		ft_putendl("Error : this is a directory.");
	return (0);
}
