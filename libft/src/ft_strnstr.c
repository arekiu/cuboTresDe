/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:23:28 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/03 11:51:23 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && i + j < len)
			{
				if (needle[j + 1] == '\0')
				{
					return ((char *)(haystack + i));
				}
				else
					j++;
			}
		}
		i++;
	}
	return (0);
}
/*#include <bsd/string.h>
//to test cc -Werror -Wall -Wextra ft_strnstr.c -lbsd

int main() {

        char stra[] = "Holislalichau";
   char strb[] = "lic";

   printf("result: %s\n", strnstr(stra, strb,10));

   char str1[] = "Holislalichau";
   char str2[] = "lic";

   printf("result FT: %s\n", ft_strnstr(str1, str2,10));

   return 0;
}*/
