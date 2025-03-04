/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:01:17 by aschmidt          #+#    #+#             */
/*   Updated: 2024/06/11 11:39:10 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_p(va_list args)
{
	void		*ptr;
	uintptr_t	ptr_num;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	else
	{
		ptr_num = (uintptr_t)ptr;
		ft_putstr_fd("0x", 1);
		return (2 + ft_put_point(ptr_num));
	}
}

int	ft_put_point(uintptr_t n)
{
	char	*base;
	char	numchar;
	int		counter;

	base = "0123456789abcdef";
	counter = 0;
	if (n > 15)
	{
		counter += ft_put_point(n / 16);
		counter += ft_put_point(n % 16);
	}
	else
	{
		numchar = base[n];
		write(1, &numchar, 1);
		counter++;
	}
	return (counter);
}
