/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 10:59:03 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/21 10:59:05 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_proj(t_param *s)
{
	int		z;
	int		i;
	int		j;

	s->color_name = "brown";
	s->color = ft_colors(s);
	i = s->y / s->scale;
	j = s->x / s->scale;
	z = s->tab[j][i] * s->high + s->deep;
	s->x2 = s->y - s->x + (s->dim_c + s->x_slide) * s->scale;
	s->y2 = (s->y + s->x - z * s->scale \
		+ (s->dim_l + s->y_slide) * s->scale) / s->perspective;
	s->z2 = z;
	if (s->max_z > 0 && s->min_z > 0)
		s->y2 += s->max_z * s->scale / s->perspective;
	if (s->max_z < 0 && s->min_z < 0)
		s->y2 += s->min_z * s->scale / s->perspective;
}

void	ft_proj_a(t_param *s)
{
	ft_proj(s);
	s->x_a = s->x2;
	s->y_a = s->y2;
	s->z_a = s->z2;
}

void	ft_proj_b(t_param *s)
{
	ft_proj(s);
	s->x_b = s->x2;
	s->y_b = s->y2;
	s->z_b = s->z2;
}

void	ft_color_altitude(t_param *s)
{
	if (s->z_a == 0 && s->z_b == 0)
		s->color_name = "brown";
	else if (s->z_a > 0 || s->z_b > 0)
		s->color_name = "green";
	else if (s->z_b < 0 || s->z_b < 0)
		s->color_name = "blue";
	s->color = ft_colors(s);
}
