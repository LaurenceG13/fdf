/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:31:58 by lagirard          #+#    #+#             */
/*   Updated: 2017/01/12 14:10:31 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *dst, char *src, size_t nb)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(dst);
	while (src[i] && i < nb)
	{
		dst[n + i] = src[i];
		i++;
	}
	dst[n + i] = '\0';
	return (dst);
}
