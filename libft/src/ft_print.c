/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:24:28 by aschmidt          #+#    #+#             */
/*   Updated: 2024/06/11 11:39:16 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_hexa(unsigned int n, char format)
{
	char	*base;
	char	numchar;
	int		counter;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	counter = 0;
	if (n > 15)
	{
		counter += ft_put_hexa(n / 16, format);
		counter += ft_put_hexa(n % 16, format);
	}
	else
	{
		numchar = base[n];
		write(1, &numchar, 1);
		counter++;
	}
	return (counter);
}

int	print_x(va_list args, char format)
{
	unsigned long	num;

	num = va_arg(args, unsigned long);
	return (ft_put_hexa(num, format));
}

int	formater(char format, va_list args)
{
	if (format == '%')
		return (print_per());
	else if (format == 'd' || format == 'i')
		return (print_d(args));
	else if (format == 'c')
		return (print_c(args));
	else if (format == 's')
		return (print_str(args));
	else if (format == 'u')
		return (print_u(args));
	else if (format == 'p')
		return (print_p(args));
	else if (format == 'x' || format == 'X')
		return (print_x(args, format));
	return (0);
}

int	ft_printf(const char *fmt_str, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!fmt_str)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, fmt_str);
	while (fmt_str[i] != '\0')
	{
		if (fmt_str[i] == '%')
		{
			count += formater(fmt_str[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar_fd(fmt_str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	// int	num = 11;
	// unsigned int  nr = 98;
	// char *str = "vieja";
	// int *p = &num;
	// ft_printf("las probabilidades son de un %d%% %s", 5589, str);
	// printf("\n");
	// printf("ORIG las probabilidades son de un %d%% %s", 5589, str);
	// //prinft si hay menos argumentos que los %, tiene comportamiento rari
	// ft_printf("%p", p);
	// printf("\n");
	// printf("%p", p);
	return (0);
}*/
