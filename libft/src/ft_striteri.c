/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:05:28 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/03 12:00:02 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int		i;

	i = 0;
	while (i < ft_strlen(s))
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
static void	custom_toupper(unsigned int index,char *ch)
{
	if (*ch >= 'a' && *ch <= 'z')
		*ch = *ch - 32;
}

int	main(void)
{
	char str[] = "holiwis";
	ft_striteri(str, &custom_toupper);
	printf("after: %s\n", str);
}*/
