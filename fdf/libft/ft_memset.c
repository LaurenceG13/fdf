/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:46:55 by lagirard          #+#    #+#             */
/*   Updated: 2017/01/12 13:43:47 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	letter;

	i = 0;
	ptr = (unsigned char *)b;
	letter = (unsigned char)c;
	while (i < len)
	{
		ptr[i] = letter;
		i++;
	}
	return (b);
}
