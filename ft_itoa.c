/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecozturk <ecozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:35:30 by ecozturk          #+#    #+#             */
/*   Updated: 2023/04/10 15:10:56 by ecozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_int_len(long nb)
{
	size_t	count;

	count = 0;
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_int_to_asci(long nb, size_t count, int flag)
{
	int		s;
	int		i;
	char	*str;

	i = 0;
	s = 1;
	str = malloc(count * sizeof(char));
	if (!str)
		return (0);
	if (flag == -1)
	{
		str[i] = '-';
		i++;
	}
	while (s <= nb / 10)
		s *= 10;
	while (s != 0)
	{
		str[i] = (nb / s % 10 + '0');
		s /= 10;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	nb;

	nb = n;
	len = ft_int_len(nb) + 1;
	if (nb < 0)
	{
		len++;
		nb *= -1;
		return (ft_int_to_asci(nb, len, -1));
	}
	else if (nb == 0)
	{
		str = malloc(2 * sizeof(char));
		str[0] = 48;
		str[1] = 0;
		return (str);
	}
	return (ft_int_to_asci(nb, len, 1));
}
