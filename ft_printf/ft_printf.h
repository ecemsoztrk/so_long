/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecozturk <ecozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:53:04 by ecozturk          #+#    #+#             */
/*   Updated: 2023/01/10 16:12:12 by ecozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	to_print(char c, va_list arg);
int	print_base(long int n, int len, char *base);
int	print_str(char *n);
int	print_char(int n);
int	p_flag(unsigned long n);

#endif
