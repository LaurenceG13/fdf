/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:42:49 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/21 16:42:50 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_size_nb(char **map)
{
	int		i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int		*ft_convert(t_param *s)
{
	int		i;
	int		*dest;

	dest = ft_memalloc_str_int(ft_size_nb(s->map));
	i = 0;
	while (s->map[i])
	{
		dest[i] = ft_atoi(s->map[i]);
		i++;
	}
	return (dest);
}
