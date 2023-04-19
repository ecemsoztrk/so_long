/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecozturk <ecozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:52:21 by ecozturk          #+#    #+#             */
/*   Updated: 2023/04/07 13:01:57 by ecozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_base(long int n, int len, char *base)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += write(1, "-", 1);
		n *= -1;
	}
	if (n >= len)
	{
		i += print_base (n / len, len, base);
		i += print_base (n % len, len, base);
	}
	else
		i += write(1, &base[n], 1);
	return (i);
}

int	print_char(int n)
{
	write (1, &n, 1);
	return (1);
}

int	print_str(char *n)
{
	int	i;

	if (!n)
		return (print_str("(null)"));
	i = 0;
	while (n[i])
	{
		i += write (1, &n[i], 1);
	}
	return (i);
}

int	p_flag(unsigned long n)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += p_flag(n / 16);
	if (n % 16 < 10)
		i += print_char((n % 16) + '0');
	else
		i += print_char((n % 16) + 87);
	return (i);
}
