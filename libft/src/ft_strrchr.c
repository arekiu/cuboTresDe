/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:07:55 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/03 11:52:15 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	unsigned char	ce;

	i = ft_strlen(str);
	ce = c;
	while (i >= 0)
	{
		if (str[i] == ce)
			return ((char *)(str + i));
		i--;
	}
	return (0);
}
/*
int     main(void)
{
        char    *str = "wow!";
        char    c = 'w';

        printf("aca esta: %s\n", strrchr(str,c));

        char    *str1 = "wow!";
        char    c1 = 'w';

        printf("aca esta FT:%s\n", ft_strrchr(str1,c1));
}*/
