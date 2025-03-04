/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:11:28 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/03 10:23:40 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*st;

	i = 0;
	st = (unsigned char *)s;
	while (i < n)
	{
		st[i] = '\0';
		i++;
	}
}
/*
int     main(void)
{
        char str[20];
        strcpy(str, "Holis chee");
        puts(str);
        bzero(str, 3);
        puts(str);
        ft_bzero(str, 3);
        puts(str);
        return 0;
}*/
