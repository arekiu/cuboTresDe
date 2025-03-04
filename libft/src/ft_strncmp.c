/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:14:58 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/07 08:56:42 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	st1;
	unsigned char	st2;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		st1 = (unsigned char)s1[i];
		st2 = (unsigned char)s2[i];
		if (st1 == st2)
			i++;
		else
			return (st1 - st2);
	}
	return (0);
}
/*
int     main(void)
{
        char *str1 = "ABCF";
        char *str2 = "ABC";
        char *s1 = "test\200";
        char *s2 = "test\0";


        printf("orig %d\n", strncmp(str1,str2, 4));
        printf("ft %d\n", ft_strncmp(str1,str2, 4));

        printf("orig %d\n", strncmp(s1,s2, 6));
        printf("ft %d\n", ft_strncmp(s1,s2, 6));
}*/
