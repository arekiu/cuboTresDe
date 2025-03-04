/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:19:31 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/03 12:08:37 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*buffer;

	size = ft_strlen(s1);
	buffer = malloc(sizeof(char) * (size + 1));
	if (buffer == NULL)
	{
		return (NULL);
	}
	ft_strcpy(buffer, (char *)s1);
	return (buffer);
}
/*
int     main()
{
        char    arr1[] = "Holandas";
        char    *p;
  printf("arr1 is %s \n", arr1);
  p = strdup(arr1);
        printf("Now p is: %s \n", p);

        char    arr2[] = "Holandas";
        char    *t;
  printf("arr1 is %s \n", arr2);
 t = ft_strdup(arr2);
 printf("Now t is: %s \n", t);

  return 0;
}*/
