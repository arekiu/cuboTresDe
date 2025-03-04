/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:26:27 by aschmidt          #+#    #+#             */
/*   Updated: 2024/06/11 11:39:21 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_len(int n)
{
	int	i;

	i = 0;
	if (n >= 0 && n < 10)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i = i + 1;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	print_d(va_list args)
{
	int	dig;

	dig = va_arg(args, int);
	ft_putnbr_fd(dig, 1);
	return (num_len(dig));
}

int	print_c(va_list args)
{
	char	ch;

	ch = va_arg(args, int);
	ft_putchar_fd(ch, 1);
	return (1);
}

int	print_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	else
		ft_putstr_fd(str, 1);
	return ((int)ft_strlen(str));
}

int	print_per(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
