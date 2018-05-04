/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 10:40:39 by lagirard          #+#    #+#             */
/*   Updated: 2017/01/11 20:00:02 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	char	**ft_fill_tab(char const *s, char **tab, char c)
{
	int		i;
	int		n;
	int		m;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		m = 0;
		if (s[i] != c && s[i])
		{
			tab[n] = (char *)malloc(sizeof(char) * (ft_size_word(s, c, i) + 1));
			if (tab[n] == NULL)
				return (NULL);
			while (s[i] != c && s[i])
				tab[n][m++] = s[i++];
			tab[n++][m] = '\0';
		}
	}
	tab[n] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (s == NULL)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_nb_words(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	tab = ft_fill_tab(s, tab, c);
	return (tab);
}
