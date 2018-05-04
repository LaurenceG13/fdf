/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 21:41:03 by lagirard          #+#    #+#             */
/*   Updated: 2016/12/23 21:55:32 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*dest;

	dest = (void *)malloc(sizeof(void) * size);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, size);
	return (dest);
}
