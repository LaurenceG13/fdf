/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 10:43:56 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/21 10:43:59 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_size_win_param(t_param *s)
{
	s->perspective = 2;
	s->scale = 50;
	s->zoom = 0;
	s->deep = 0;
	s->high = 1;
	s->dim_l = s->nb_columns - 1;
	s->dim_c = s->nb_lines - 1;
	if (s->nb_lines == 1 && s->nb_columns == 1)
	{
		s->dim_l = 1;
		s->dim_c = 1;
	}
	s->x_win = s->dim_l * s->scale + 1;
	s->y_win = s->dim_c * s->scale + 1;
	s->x_slide = 0;
	s->y_slide = 0;
}

void	ft_size_win(t_param *s)
{
	ft_size_win_param(s);
	while ((s->x_win > 500 || s->y_win > 500) && s->scale > 1 && s->x_win > 0 \
		&& s->y_win > 0)
	{
		s->scale = s->scale - 1;
		s->x_win = s->dim_l * s->scale + 1;
		s->y_win = s->dim_c * s->scale + 1;
	}
	if (s->dim_c > s->dim_l)
	{
		s->x_win = s->perspective * s->x_win + (s->dim_c - s->dim_l) * s->scale;
		s->y_win = s->perspective * s->y_win + s->scale;
	}
	if (s->dim_l > s->dim_c)
	{
		s->x_win = s->perspective * s->x_win + s->scale;
		s->y_win = s->perspective * s->y_win + (s->dim_l - s->dim_c) * s->scale;
	}
	if (s->dim_l == s->dim_c)
	{
		s->x_win = s->perspective * s->x_win;
		s->y_win = s->perspective * s->y_win;
	}
}
