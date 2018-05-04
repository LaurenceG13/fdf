/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.ch                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 13:50:23 by lagirard          #+#    #+#             */
/*   Updated: 2017/07/24 22:04:16 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_put_point_img(t_param *s, int x, int y)
{
	if (x < s->x_win && y < s->y_win && x >= 0 && y >= 0)
		s->str_img[y * s->x_win + x] = s->color;
}

int				ft_draw_diagonale(t_param *s)
{
	int		x;
	int		y;

	x = s->x_a;
	y = s->y_a;
	while (x != s->x_b || y != s->y_b)
	{
		s->e2 = 2 * s->e;
		ft_put_point_img(s, x, y);
		if (s->e2 >= -s->dy)
		{
			s->e -= s->dy;
			x += s->sx;
		}
		if (s->e2 <= s->dx)
		{
			s->e += s->dx;
			y += s->sy;
		}
	}
	ft_put_point_img(s, x, y);
	return (0);
}

int				ft_draw_vertical(t_param *s)
{
	int		x;
	int		y;

	x = s->x_a;
	y = s->y_a;
	if (x == s->x_b)
	{
		while (y != s->y_b)
		{
			s->e2 = 2 * s->e;
			ft_put_point_img(s, x, y);
			if (s->e2 <= s->dx)
			{
				s->e += s->dx;
				y += s->sy;
			}
		}
		ft_put_point_img(s, x, y);
		return (0);
	}
	return (0);
}

int				ft_draw_horizontal(t_param *s)
{
	int		x;
	int		y;

	x = s->x_a;
	y = s->y_a;
	if (y == s->y_b)
	{
		while (x != s->x_b)
		{
			s->e2 = 2 * s->e;
			ft_put_point_img(s, x, y);
			if (s->e2 >= -s->dy)
			{
				s->e -= s->dy;
				x += s->sx;
			}
		}
		ft_put_point_img(s, x, y);
		return (0);
	}
	return (0);
}

int				ft_draw_segment(t_param *s)
{
	int		x;
	int		y;

	s->str_img = (int *)mlx_get_data_addr(s->img, \
		&(s->bpp), &(s->s_l), &(s->endian));
	x = s->x_a;
	y = s->y_a;
	s->dx = abs(s->x_b - s->x_a);
	s->dy = abs(s->y_b - s->y_a);
	s->sx = s->x_a < s->x_b ? 1 : -1;
	s->sy = s->y_a < s->y_b ? 1 : -1;
	s->e = s->dx - s->dy;
	if (s->x_a == s->x_b)
		return (ft_draw_vertical(s));
	if (s->y_a == s->y_b)
		return (ft_draw_horizontal(s));
	return (ft_draw_diagonale(s));
}
