/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 18:17:43 by lagirard          #+#    #+#             */
/*   Updated: 2016/12/23 19:30:00 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		r;

	if (s1 && s2)
	{
		if (ft_strncmp(s1, s2, n) != 0)
			r = 0;
		else
			r = 1;
		return (r);
	}
	return (0);
}
