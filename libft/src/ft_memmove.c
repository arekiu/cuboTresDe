/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:43:02 by aschmidt          #+#    #+#             */
/*   Updated: 2024/04/30 15:24:09 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (!str1 && !str2)
		return (NULL);
	if ((unsigned char *)str1 > (unsigned char *)str2)
	{
		while (n > 0)
		{
			((unsigned char *)str1)[n - 1] = ((unsigned char *)str2)[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)str1)[i] = ((unsigned char *)str2)[i];
			i++;
		}
	}
	return (str1);
}
/*
int main ()
{
  char str[] = "memmove can be very useful......";
  ft_memmove(str+20,str+15,11);
  puts(str);
  return 0;
}*/
