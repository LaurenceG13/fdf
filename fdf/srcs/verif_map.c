/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 12:17:18 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/21 12:17:19 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_count_lines(char *str, t_param *s)
{
	int		i;
	int		fd;
	char	*line;

	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_putendl("Error : File doesn't open");
		return (-1);
	}
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_isvalid(line) == -1)
		{
			ft_putendl("Error : the map is invalid");
			return (-1);
		}
		i++;
		free(line);
		line = NULL;
	}
	s->nb_lines = i;
	close(fd);
	return (0);
}

int		ft_count_columns(char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		if (line[i] == ' ' && line[i - 1] != ' ')
			count++;
		i++;
	}
	if (i > 0 && line[i - 1] != ' ')
		count++;
	return (count);
}

int		*ft_memalloc_str_int(int size)
{
	int		*dest;

	if (!(dest = (int *)malloc(sizeof(int) * (size + 1))))
		return (NULL);
	ft_bzero(dest, size);
	return (dest);
}

int		**ft_memalloc_tab_int(int size)
{
	int		**dest;

	if (!(dest = (int **)malloc(sizeof(int *) * (size + 1))))
		return (NULL);
	return (dest);
}
