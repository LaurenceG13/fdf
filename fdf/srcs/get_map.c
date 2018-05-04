/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.ch                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 13:50:23 by lagirard          #+#    #+#             */
/*   Updated: 2017/08/16 18:01:01 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_minmax_z(t_param *s)
{
	int		i;
	int		j;

	i = 0;
	s->min_z = s->tab[0][0];
	s->max_z = s->tab[0][0];
	while (i < s->nb_lines)
	{
		j = 0;
		while (j < s->nb_columns)
		{
			if (s->tab[i][j] <= s->min_z)
				s->min_z = s->tab[i][j];
			else if (s->tab[i][j] >= s->max_z)
				s->max_z = s->tab[i][j];
			j++;
		}
		i++;
	}
}

int		ft_split_error1(t_param *s, char *line, int i)
{
	if (ft_isvalid(line) == -1)
	{
		ft_putendl("Error : the map is invalid.");
		return (-1);
	}
	s->nb_columns = ft_count_columns(line);
	if (i == 0)
		s->nbcol_first = s->nb_columns;
	if (s->nbcol_first != s->nb_columns)
	{
		ft_putendl("Error : found wrong line length. Exiting.");
		return (-1);
	}
	if ((s->map = ft_strsplit(line, ' ')) == NULL)
	{
		ft_putendl("Error : map NULL --> ft_strsplit failed");
		return (-1);
	}
	if ((s->tab[i] = ft_convert(s)) == NULL)
	{
		ft_putendl("Error : tab[i] == NULL --> ft_convert failed");
		return (-1);
	}
	return (0);
}

int		ft_split_error2(t_param *s, int i)
{
	s->nb_lines = i;
	if (s->nb_columns < 1 && s->nb_lines < 1)
	{
		ft_putendl("Error : map not valid (empty)");
		return (-1);
	}
	ft_minmax_z(s);
	return (0);
}

void	ft_split_init(t_param *s)
{
	s->tab = ft_memalloc_tab_int(s->nb_lines);
	s->nb_columns = -1;
	s->nbcol_first = -1;
}

int		ft_split(char *str, t_param *s)
{
	int		i;
	int		fd;
	char	*line;

	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_putendl("Error : can't open file");
		return (-1);
	}
	ft_split_init(s);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_split_error1(s, line, i) == -1)
			return (-1);
		i++;
		free(line);
		line = NULL;
		ft_free_map(s->map);
	}
	if (ft_split_error2(s, i) == -1)
		return (-1);
	close(fd);
	return (0);
}
