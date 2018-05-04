/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:31:58 by lagirard          #+#    #+#             */
/*   Updated: 2017/01/12 14:11:52 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	int		i;
	int		n;

	i = 0;
	n = ft_strlen(dst);
	while (src[i])
	{
		dst[n + i] = src[i];
		i++;
	}
	dst[n + i] = '\0';
	return (dst);
}
