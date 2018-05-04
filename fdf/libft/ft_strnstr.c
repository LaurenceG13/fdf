/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:43:04 by lagirard          #+#    #+#             */
/*   Updated: 2016/12/23 17:22:56 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t m)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = (size_t)ft_strlen((char *)to_find);
	if (n == 0)
		return ((char *)str);
	while (str[i] && (n + i) <= m)
	{
		if (ft_strncmp(&str[i], to_find, n) == 0)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
