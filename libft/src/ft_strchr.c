/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:37:23 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/03 11:44:31 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	ce;

	i = 0;
	ce = c;
	while (str[i] != '\0')
	{
		if (str[i] == ce)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == ce)
		return ((char *)(str + i));
	return (0);
}
/*
int     main(void)
{
        char    *str = "habia una vez un circo";
        char    c = 'w';

        printf("aca esta: %s\n", strchr(str,c));

        char    *str1 = "habia una vez un circo";
        char    c1 = 'w';

        printf("aca esta FT:%s\n", ft_strchr(str1,c1));
}*/
