/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 11:17:05 by lagirard          #+#    #+#             */
/*   Updated: 2017/08/10 19:08:05 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_colors(t_param *s)
{
	int		color;

	if (ft_strncmp(s->color_name, "white", 4) == 0)
		color = 0x00FFFFFF;
	if (ft_strncmp(s->color_name, "brown", 4) == 0)
		color = 0x006A3C00;
	if (ft_strncmp(s->color_name, "green", 4) == 0)
		color = 0x00004929;
	if (ft_strncmp(s->color_name, "blue", 4) == 0)
		color = 0x00057ED;
	return (color);
}
