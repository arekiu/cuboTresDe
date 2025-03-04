/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:41:43 by aschmidt          #+#    #+#             */
/*   Updated: 2024/04/30 13:29:00 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*new_str;
	unsigned int		i;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_str)
		return (NULL);
	while (i < ft_strlen(s))
	{
		new_str[i] = (*f)(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*
static char     custom_toupper(unsigned int index,char ch)
{
        if (ch >= 'a' && ch <= 'z')
                ch = ch - 32;
        return (ch);
}

int	main(void)
{
	char *str = "holiwis";
	printf("after: %s\n", ft_strmapi(str, &custom_toupper));
}*/
