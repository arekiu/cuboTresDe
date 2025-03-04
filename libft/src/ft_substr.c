/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:54:47 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/03 11:54:15 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (start > ft_strlen(str))
	{
		len = 0;
	}
	if (len != 0 && len > ft_strlen(str + start))
		len = ft_strlen(str + start);
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len && str)
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
int     main(void)
{
        char *str = "la wea fome";

        printf("FT: %s\n", ft_substr(str, 2, 20));
}*/
