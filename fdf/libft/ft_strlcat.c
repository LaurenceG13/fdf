/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:31:58 by lagirard          #+#    #+#             */
/*   Updated: 2017/01/12 14:12:02 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t nb)
{
	size_t	i;
	size_t	s;
	size_t	d;

	i = 0;
	s = ft_strlen((char *)src);
	d = ft_strlen(dst);
	if (nb == 0)
		return (s + nb);
	while (src[i] && (d + i) < (nb - 1))
	{
		dst[d + i] = src[i];
		i++;
	}
	if (d > nb)
		return (s + nb);
	else
	{
		dst[d + i] = '\0';
		return (s + d);
	}
}
