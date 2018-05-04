/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.ch                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 13:50:23 by lagirard          #+#    #+#             */
/*   Updated: 2017/08/06 17:20:48 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free_map(char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (map == NULL)
		return ;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			map[i][j] = 0;
			j++;
		}
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

void	ft_free_tab(t_param *s)
{
	int		i;

	i = 0;
	if (s->tab == NULL)
		return ;
	while (i < s->nb_lines)
	{
		s->tab[i] = NULL;
		i++;
	}
	free(s->tab);
}
