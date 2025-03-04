/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:03:07 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/03 11:43:24 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*desti;
	unsigned char	*sourc;
	size_t			i;

	if (!dest && !src)
		return (dest);
	desti = (unsigned char *)dest;
	sourc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		desti[i] = sourc[i];
		i++;
	}
	return (dest);
}
/*
int main () {
   const char src[30] = "anoche no dormi";
   char dest[30];
   strcpy(dest,"Holis me fui a la chota!");
 printf("Before memcpy dest = %s\n", dest);
   memcpy(dest, src, 5);
   printf("After memcpy dest = %s\n", dest);
//     printf("Before ft_memcpy dest = %s\n", dest);
//    ft_memcpy(dest, src, 5);
//    printf("After ft_memcpy dest = %s\n", dest);

   return(0);
}*/
