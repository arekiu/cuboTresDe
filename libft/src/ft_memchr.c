/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:26:21 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/03 11:41:33 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	ch;

	i = 0;
	str = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)(str + i));
		i++;
	}
	return (0);
}
/*
int     main(void)
{
        char    *str = "donde estan los ladrones";
        char    c = 'x';

        printf("aca esta: %s\n", memchr(str,c,10));

        char    *str1 = "donde estan los ladrones";
        char    c1 = 'x';

        printf("aca esta FT: %s\n", ft_memchr(str1,c1,10));
}*/
