/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:46:19 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/03 11:57:36 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	i;

	i = 0;
	if (n >= 0 && n < 10)
		return (1);
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

char	*ft_itoa(int n)
{
	int		i;
	int		count;
	char	*num_char;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = num_len(n);
	i = 0;
	num_char = (char *)malloc(sizeof(char) * (count + 1));
	if (!num_char)
		return (NULL);
	if (n < 0)
	{
		num_char[0] = '-';
		n = n * -1;
		i++;
	}
	num_char[count] = '\0';
	while (i < count)
	{
		num_char[count - 1] = ((n % 10) + 48);
		n = n / 10;
		count--;
	}
	return (num_char);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(-4542));
}*/
