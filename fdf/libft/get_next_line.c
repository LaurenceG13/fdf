/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:41:02 by lagirard          #+#    #+#             */
/*   Updated: 2017/07/22 10:32:31 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmerge(char *s1, char *s2)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (new);
}

char	*ft_gnlbis(t_struct *s, char *rest)
{
	if (rest != NULL)
	{
		s->tmp = (char *)malloc(sizeof(char) * (ft_strlen(rest) + 1));
		if (s->tmp == NULL)
			return (NULL);
		s->tmp = ft_strcpy(s->tmp, rest);
	}
	else
		s->tmp = ft_strnew(0);
	ft_strdel(&rest);
	return (rest);
}

int		ft_gnlter(int ret, t_struct *s)
{
	if (ret == -1)
		return (-1);
	if (ret == 0 && ft_strchr(s->tmp, '\n') == NULL)
	{
		if (ft_strlen(s->tmp) > 0)
			return (1);
		ft_strdel(&s->tmp);
		return (0);
	}
	ft_strdel(&s->tmp);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*rest = NULL;
	int			ret;
	char		buff[BUFF_SIZE + 1];
	t_struct	s;

	if (line == NULL)
		return (-1);
	*line = NULL;
	rest = ft_gnlbis(&s, rest);
	while (ft_strchr(s.tmp, '\n') == NULL)
	{
		*line = s.tmp;
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1 || (ret == 0 && ft_strchr(s.tmp, '\n') == NULL))
			return (ft_gnlter(ret, &s));
		buff[ret] = '\0';
		s.tmp = ft_strmerge(s.tmp, buff);
	}
	rest = ft_strdup(ft_strchr(s.tmp, '\n') + 1);
	*line = ft_strsub(s.tmp, 0, ft_strlen(s.tmp) - ft_strlen(rest) - 1);
	ft_strdel(&s.tmp);
	return (1);
}
