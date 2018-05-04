/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.ch                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 13:50:23 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/21 10:58:44 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_horizontal(t_param *s, int tmp_x, int tmp_y)
{
	tmp_x = 0;
	tmp_y = 0;
	s->x = 0;
	while (s->x <= s->dim_c * s->scale)
	{
		s->y = 0;
		while (s->y <= s->dim_l * s->scale)
		{
			tmp_x = s->x;
			tmp_y = s->y;
			ft_proj_a(s);
			s->y += s->scale;
			if (s->y <= s->dim_l * s->scale)
				ft_proj_b(s);
			ft_color_altitude(s);
			ft_draw_segment(s);
		}
		s->x = tmp_x;
		s->y = tmp_y;
		s->x += s->scale;
	}
}

void	ft_vertical(t_param *s, int tmp_x, int tmp_y)
{
	tmp_x = 0;
	tmp_y = 0;
	s->y = 0;
	while (s->y <= s->dim_l * s->scale)
	{
		s->x = 0;
		while (s->x <= s->dim_c * s->scale)
		{
			tmp_x = s->x;
			tmp_y = s->y;
			ft_proj_a(s);
			s->x += s->scale;
			if (s->x <= s->dim_c * s->scale)
				ft_proj_b(s);
			ft_color_altitude(s);
			ft_draw_segment(s);
		}
		s->x = tmp_x;
		s->y = tmp_y;
		s->y += s->scale;
	}
}

void	ft_point(t_param *s)
{
	s->x = 0;
	s->y = 0;
	ft_proj_a(s);
	ft_proj_b(s);
	ft_color_altitude(s);
	ft_draw_segment(s);
}

void	ft_trace_touching_points(t_param *s)
{
	int		tmp_x;
	int		tmp_y;

	tmp_x = 0;
	tmp_y = 0;
	if (s->nb_lines == 1 && s->nb_columns == 1)
	{
		s->img = mlx_new_image(s->mlx, s->x_win, s->y_win);
		ft_point(s);
		s->putimg = mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	}
	else
	{
		s->img = mlx_new_image(s->mlx, s->x_win, s->y_win);
		if (s->nb_lines != 1)
			ft_vertical(s, tmp_x, tmp_y);
		if (s->nb_columns != 1)
			ft_horizontal(s, tmp_x, tmp_y);
		s->putimg = mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	}
}
