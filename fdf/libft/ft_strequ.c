/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 18:17:43 by lagirard          #+#    #+#             */
/*   Updated: 2016/12/23 19:29:23 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		n;

	if (s1 && s2)
	{
		if (ft_strcmp(s1, s2) != 0)
			n = 0;
		else
			n = 1;
		return (n);
	}
	return (0);
}
