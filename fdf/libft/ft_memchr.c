/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:37:41 by lagirard          #+#    #+#             */
/*   Updated: 2017/01/12 14:09:52 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	letter;

	i = 0;
	ptr = (unsigned char *)s;
	letter = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == letter)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
