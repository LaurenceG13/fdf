/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.ch                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 13:50:23 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/23 01:33:12 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_again(t_param *s)
{
	mlx_clear_window(s->mlx, s->win);
	mlx_destroy_image(s->mlx, s->img);
	ft_trace_touching_points(s);
}

void	ft_sea(t_param *s)
{
	if (s->key == 4)
	{
		s->deep = s->deep + 10;
		s->y_slide = s->y_slide + 10;
	}
	if (s->key == 11)
	{
		s->deep = s->deep - 10;
		s->y_slide = s->y_slide - 10;
	}
}

void	ft_slide(t_param *s)
{
	if (s->key == 123)
		s->x_slide = s->x_slide - 10;
	if (s->key == 124)
		s->x_slide = s->x_slide + 10;
	if (s->key == 125)
		s->y_slide = s->y_slide + 10;
	if (s->key == 126)
		s->y_slide = s->y_slide - 10;
}

void	ft_high(t_param *s)
{
	if (s->key == 35)
		s->high = s->high + 1;
	if (s->key == 46)
		s->high = s->high - 1;
}

int		ft_keycode(int keycode, void *blabla)
{
	t_param	*s;

	s = (t_param *)blabla;
	s->key = keycode;
	if (s->key == 53)
		exit(0);
	if (s->key == 69)
		s->scale = s->scale + 1;
	if (s->key == 78 && s->scale - 1 > 0)
		s->scale = s->scale - 1;
	if (s->key == 4 || s->key == 11)
		ft_sea(s);
	if (s->key >= 123 && s->key <= 126)
		ft_slide(s);
	if (s->key == 35 || s->key == 46)
		ft_high(s);
	if (s->key == 36)
		ft_size_win(s);
	ft_again(s);
	return (0);
}
