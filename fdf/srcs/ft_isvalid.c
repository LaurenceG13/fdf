/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 12:42:32 by lagirard          #+#    #+#             */
/*   Updated: 2017/10/21 12:42:40 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_isvalid_error1(char *line, int i)
{
	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0 && line[i] != ' ' && line[i] != '-' \
		&& line[i] != '+')
			return (-1);
		if ((i > 0) && (line[i - 1] == '-' || line[i - 1] == '+') && \
		ft_isdigit(line[i]) == 0)
			return (-1);
		i++;
	}
	return (i);
}

int		ft_isvalid_error2(char *line, int i, int j)
{
	while (j < 8 && line[i])
	{
		if (ft_isdigit(line[i + j]) == 0 \
		&& ft_isalpha(line[i + j]) == 0)
			return (-1);
		j++;
	}
	if (j != 7)
		return (-1);
	return (j);
}

int		ft_isvalid(char *line)
{
	int		i;

	i = 0;
	if ((i = ft_isvalid_error1(line, i) == -1))
		return (-1);
	return (0);
}
