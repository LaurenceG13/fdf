/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:07:13 by lagirard          #+#    #+#             */
/*   Updated: 2017/01/11 19:07:18 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int n;

	n = nb;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	if (nb >= 13)
		return (0);
	if (nb > 0 && n < 13)
	{
		n = n * ft_recursive_factorial(nb - 1);
		return (n);
	}
	return (0);
}
