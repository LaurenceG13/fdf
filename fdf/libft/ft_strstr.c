/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 12:45:41 by lagirard          #+#    #+#             */
/*   Updated: 2016/12/23 14:02:27 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		n;

	i = 0;
	n = ft_strlen((char *)to_find);
	if (n == 0)
		return ((char *)str);
	while (str[i])
	{
		if (ft_strncmp(&str[i], to_find, n) == 0)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
