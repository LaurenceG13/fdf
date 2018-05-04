/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 20:29:42 by lagirard          #+#    #+#             */
/*   Updated: 2016/12/23 21:39:52 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		a;
	size_t		b;
	char		*dest;

	if (s == NULL)
		return (NULL);
	a = 0;
	b = ft_strlen(s) - 1;
	while (s[a] && (s[a] == ' ' || s[a] == '\n' || s[a] == '\t'))
		a++;
	while ((s[b] == ' ' || s[b] == '\n' || s[b] == '\t') && a < b)
		b--;
	dest = (char *)malloc(sizeof(char) * (b - a + 2));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < b - a + 1)
	{
		dest[i] = s[a + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
